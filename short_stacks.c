/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:39:12 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 13:39:12 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rr(stack_a, stack_b);
	new_index(*stack_a);
	new_index(*stack_b);
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
							t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	new_index(*stack_a);
	new_index(*stack_b);
}

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}

static void	min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->data != find_min(*stack_a)->data)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3)
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !sorted_stack(*stack_a))
		pb(stack_b, stack_a);
	while (len_a-- > 3 && !sorted_stack(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	new_index(*stack_a);
	min_on_top(stack_a);
}
