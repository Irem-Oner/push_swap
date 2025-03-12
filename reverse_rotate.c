/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:39:37 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:39:37 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = find_last(*stack_a);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
}
void	rra(t_stack **stack_a)
{
	reverse_rotate_a(stack_a);
	ft_printf("rra\n");
}
static void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = find_last(*stack_b);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_b(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
