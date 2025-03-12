/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioner <ioner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:24:41 by ioner             #+#    #+#             */
/*   Updated: 2025/03/11 16:39:14 by ioner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775807
# endif

typedef struct s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				data;
	int				index;
	int				above_median;
	int				push_cost;
	int				cheapest;

	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		error_syntax(char *str);
int		duplicate_check(t_stack *stack_a, int n);
void	free_stack(t_stack **stack);
void	free_error(t_stack **satck_a, char **args, int flag);
void	free_args(char **args);
int		ft_atoi(char *input);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	set_cheapest(t_stack *stack);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	init_stack(t_stack **stack_a, char **av, int flag);
t_stack	*find_last(t_stack *stack);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	three_sort(t_stack **stack_a);
int		sorted_stack(t_stack *stack);
int		stack_len(t_stack *stack);
void	new_index(t_stack *stack);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	write_error(void);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	sa(t_stack	**stack_a);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);

#endif
