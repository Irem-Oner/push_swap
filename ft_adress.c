/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:42:18 by ioner             #+#    #+#             */
/*   Updated: 2024/11/19 15:37:47 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned long n)
{
	char	*digit;
	int		len;

	len = 0;
	digit = "0123456789abcdef";
	if (n < 16)
	{
		if (ft_putchar(digit[n]) == -1)
			return (-1);
		return (1);
	}
	else
	{
		len += ft_hex(n / 16);
		if (ft_putchar(digit[n % 16]) == -1)
			return (-1);
		return (len + 1);
	}
}

int	ft_adress(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_hex((unsigned long) ptr);
	if (len != -1)
		return (len + 2);
	else
		return (-1);
}
