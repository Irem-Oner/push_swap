/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:42:14 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:42:14 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;

	if (!stack_b || !(*stack_b))
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	top_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = top_b;
	*stack_a = top_b;
	top_b->prev = NULL;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*top_a;

	if (!stack_a || !(*stack_a))
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	top_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = top_a;
	*stack_b = top_a;
	top_a->prev = NULL;
	ft_printf("pb\n");
}
