/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:40:48 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:40:50 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	count_word;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count_word++;
		i++;
	}
	return (count_word);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_str(s, c);
	new_str = malloc(sizeof(char *) * (count + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			new_str[i] = ft_substr(s, 0, word_len(s, c));
			if (!new_str[i++])
				return (free_str(new_str));
			s += word_len(s, c);
		}
		else
			s++;
	}
	new_str[i] = NULL;
	return (new_str);
}
