/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:39:18 by bhenne            #+#    #+#             */
/*   Updated: 2015/02/27 19:39:53 by bhenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 100

typedef struct      s_file
{
	int				fd;
	char			*buff;
	struct s_file	*next;
}					t_file;
int					gnl(int const fd, char **line);
#endif
