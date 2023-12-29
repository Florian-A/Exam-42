/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 16:42:46 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putstr_mod(char *s)
{
	int	i;

	i = 0;
	while(s[i++])
		write(1, &s[i - 1], 1);
	return (i - 1);
}

int convert_base(unsigned n, char *base, unsigned blen, int i)
{
	if(n >= blen)
		i += convert_base(n / blen, base, blen, i);
	write(1, &base[n % blen], 1);
	return (i + 1);
}

int ft_itoa_mod(int n)
{
	int i;
	unsigned nb;
	
	i = 0;
	if (n < 0)
	{
		nb = -n;
		i++;
		write(1, "-", 1);
	}
	else
		nb = n;
	i += convert_base(nb, "01", 2, 0);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int	len;
	char *s;
	int	d;
	unsigned x;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if(fmt[0] == '%' && fmt[1] == 's')
		{
			s = va_arg(ap, char *);
			len += ft_putstr_mod(s);
			fmt++;
		}
		else if(fmt[0] == '%' && fmt[1] == 'd')
		{
			d = va_arg(ap, int);
			len += ft_itoa_mod(d);
			fmt++;
		}
		else if(fmt[0] == '%' && fmt[1] == 'x')
		{
			x = va_arg(ap, unsigned);
			len += convert_base(x, "0123456789abcdef", 16, 0);
			fmt++;
		}
		else
		{
			ft_putchar(fmt[0]);
			len++;
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
