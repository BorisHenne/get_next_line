/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenne <bhenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:02:44 by bhenne            #+#    #+#             */
/*   Updated: 2015/01/14 21:23:51 by bhenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(char **str, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*s;

	ret = read (fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = 0;
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (*s != 0)
		free (s);
	return (ret);
}

static int		ft_load(char **str, char **line, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	tmp = ft_strjoin(s + 1, "");
	free(*str);
	*str = tmp;
	if (**line)
		return (1);
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static char *str;
	char		*s;
	int			ret;

	if (str == 0)
		str = ft_strdup("");
	if (!line || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (1)
	{
		s = str;
		while (*s || ret < BUFF_SIZE)
		{
			if (*s == '\n' || *s == 0 || *s == -1)
				return (ft_load(&str, line, s));
			s++;
		}
		ret = ft_read(&str, fd);
		if (ret == -1)
			return (-1);
	}
}
