/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:05:31 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s)
{
	int	i;
	
	i = 0;
	while(s[i++])
		write(1, &s[i-1], 1);
}

int is_uniq(char c, char *s)
{
	int i;

	i = 0;
	while(s[i++])
		if(c == s[i-1])
			return(0);
	return (1);
}

void show_union(char *s1, char *s2)
{
	char buffer[128] = {0};
	int i;
	int j;

	i = 0;
	j = 0;
	while(s1[i++])
		if(is_uniq(s1[i-1], buffer))
			buffer[j++] = s1[i-1];
	i = 0;
	while(s2[i++])
		if(is_uniq(s2[i-1], buffer))
			buffer[j++] = s2[i-1];

	ft_putstr(buffer);
}


int main(int argc, char **argv)
{
    if (argc == 3)
		show_union(argv[1], argv[2]);
	ft_putstr("\n");

	return(0);
}

