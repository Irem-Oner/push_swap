/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:39:47 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:47:14 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	null_check(void *stack)
{
	if (stack == NULL)
		write_error();
	else
		return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		init_stack(&stack_a, av, ac == 2);
	}
	else
		init_stack(&stack_a, av + 1, ac == 2);
	null_check(stack_a);
	if (!sorted_stack(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			three_sort(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	return (free_stack(&stack_a), 0);
}
