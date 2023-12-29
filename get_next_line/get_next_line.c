/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:04:36 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char *s = malloc(10000);
	char *c;

	s = c;

	while (read(fd, c, 1) > 0)
	{
		if (*c == '\n')
		{
			++c;
			break;
		}
		++c;
	}
	if (c > s)
	{
		*s = '\0';
		return (s);
	}
	free(s);
	return (NULL);
}