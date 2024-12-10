/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:30:06 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 09:56:46 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_specifier(va_list arg, char const specifier)
{
	if (specifier == 'd')
		print_int(va_arg(arg, int));
	else if (specifier == 's')
		print_str(va_arg(arg, char *));
}

void	ft_printf(const char *format, ...)
{
	va_list	arg;

	if (!format)
		return ;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			find_specifier(arg, *format);
		}
		else
			print_char(*format);
		format++;
	}
	va_end(arg);
}

void	print_char(char c)
{
	write (1, &c, 1);
}

void	print_int(int n)
{
	int	d;

	if (n == -2147483648)
	{
		print_str("-2147483648");
		return ;
	}
	d = 1;
	if (n < 0)
	{
		n = -n;
		print_char('-');
	}
	while (n / d > 9)
		d *= 10;
	while (d)
	{
		print_char(n / d + '0');
		n = n % d;
		d /= 10;
	}
}

void	print_str(char *str)
{
	if (!str)
		return (print_str("(null)"));
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}
