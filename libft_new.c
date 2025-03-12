/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:41:20 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:41:20 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *input)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((input[i] >= 9 && input[i] <= 13) || (input[i] == 32))
		i++;
	if (input[i] == '-' || input[i] == '+')
	{
		if (input[i] == '-')
			sign = -1;
		i++;
	}
	while (input[i] >= '0' && input[i] <= '9')
	{
		res = res * 10 + input[i] - '0';
		i++;
	}
	return (res * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	while (i < len && s[i + start])
		i++;
	ptr = (char *)malloc((i) + 1);
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

void	write_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
