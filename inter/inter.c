/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:04:42 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	while(s[i++])
		write(1, &s[i-1], 1);
}

int is_uniq(char c, char *s1)
{
	int		i;
	int		found;	

	i = 0;
	found = 0;
	while(s1[i++])
	{
		found = 0;
		if(c == s1[i-1])
		{
			found = 1;
			break;
		}
	}
	if(found == 0)
		return (1);
	else
		return (0);
}

void inter(char	*s1, char *s2)
{
	char buffer[128];
	int i;
	int p;

	i = 0;
	p = 0;
	while(s1[i++])
		if(!is_uniq(s1[i-1], s2))
			if(is_uniq(s1[i-1], buffer))
				buffer[p++] = s1[i-1];
	i = 0;
	while(s2[i++])
		if(!is_uniq(s2[i-1], s1))
			if(is_uniq(s2[i-1], buffer))
				buffer[p++] = s2[i-1];
	ft_putstr(buffer);
}

int main(int argc, char **argv)
{
	if(argc == 3)
		inter(argv[1], argv[2]);
	ft_putstr("\n");
	return (0);
}
