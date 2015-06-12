/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:36:11 by bhenne            #+#    #+#             */
/*   Updated: 2015/02/27 19:39:10 by bhenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "gnl.h"

static char			*return_char_buff(int const fd)
{
	char *buff;
	char *tmp[2];

	buff = ft_strnew(BUFF_SIZE);
	tmp[0] = NULL;
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE))
	{
		tmp[1] = tmp[0];
		tmp[0] = ft_strappend(tmp[1], buff);
		if (tmp[1])
			free(tmp[1]);
		if ((ft_strchr(tmp[0], '\n')))
		{
			free(buff);
			return (tmp[0]);
		}
		ft_memset(buff, '\0', BUFF_SIZE + 1);
	}
	free(buff);
	return (tmp[0]);
}

static t_file		*new_file(int fd)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->fd =fd;
	file->buff = return_char_buff(fd);
	file->next = NULL;
	return (file);
}

static t_file		*return_file_info(int fd, t_file *file)
{
	t_file *cursor;
	t_file *previous_cursor;

	cursor = file;
	if (file == NULL)
		cursor = new_file(fd);
	else
	{
		while (cursor != NULL)
		{
			previous_cursor = cursor;
			if (cursor->fd == fd)
				return (cursor);
			cursor = cursor->next;
		}
		previous_cursor->next = new_file(fd);
		cursor = previous_cursor->next;
	}
	return (cursor);
}

static int			return_gnl(t_file *file, char **line, int i)
{
	if (!file->buff || (!ft_strchr(file->buff, '\n') && i == 0))
		return (0);
	if (!ft_strchr(file->buff, ))
}