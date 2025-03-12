/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:41:15 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:41:15 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

static int	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (0);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->next = NULL;
	node->data = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

void	init_stack(t_stack **stack_a, char **av, int flag)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_error(stack_a, av, flag);
		n = ft_atol(av[i]);
		if (n > 2147483647 || n < -2147483648)
			free_error(stack_a, av, flag);
		if (duplicate_check(*stack_a, (int)n))
			free_error(stack_a, av, flag);
		if (!(append_node(stack_a, (int)n)))
			free_error(stack_a, av, flag);
		i++;
	}
	if (flag)
		free_args(av);
}
