/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:38:56 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:38:56 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->data > second->data && second->data > third->data)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first->data > second->data && first->data > third->data)
		ra(stack_a);
	else if (first->data > second->data)
		sa(stack_a);
	else if (second->data > third->data && first->data < third->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (second->data > third->data)
		rra(stack_a);
}
