/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenne <bhenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 21:50:04 by bhenne            #+#    #+#             */
/*   Updated: 2015/01/14 21:26:48 by bhenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft.h"
#include <string.h>
#define BUFF_SIZE 8

int get_next_line(int const fd, char **line);

#	endif
