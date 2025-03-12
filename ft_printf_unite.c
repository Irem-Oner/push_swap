/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:09:52 by ioner             #+#    #+#             */
/*   Updated: 2024/11/19 14:07:09 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_digit_hex(unsigned int n, char c)
{
	char	*digit;
	int		len;

	len = 0;
	if (c == 'x')
		digit = "0123456789abcdef";
	else if (c == 'X')
		digit = "0123456789ABCDEF";
	else
		return (-1);
	if (n < 16)
	{
		if (write(1, &digit[n % 16], 1) == -1)
			return (-1);
		return (1);
	}
	len += ft_digit_hex(n / 16, c);
	if (write(1, &digit[n % 16], 1) == -1)
		return (-1);
	return (len + 1);
}	
