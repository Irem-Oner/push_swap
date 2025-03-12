/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:49:06 by ioner             #+#    #+#             */
/*   Updated: 2024/11/19 16:32:19 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_format(const char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'p')
		return (ft_adress(va_arg(*args, void *)));
	else if (format == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_digit_hex(va_arg(*args, unsigned int), format));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

static int	ft_format_check(char str)
{
	return (str == 'c' || str == 'd' || str == 'i' || str == 'p'
		|| str == 'u' || str == 'x' || str == 'X' || str == 's'
		|| str == '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		ctrl;

	i = -1;
	len = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%' && ft_format_check(format[i + 1]))
		{
			ctrl = ft_format(format[++i], &args);
			if (ctrl == -1)
				return (-1);
			len += ctrl;
		}
		else if ((ft_putchar(format[i])) == -1)
			return (-1);
		else if (format[i] != '%')
			len++;
	}
	return (va_end(args), len);
}
