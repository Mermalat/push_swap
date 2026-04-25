/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:19:00 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 18:19:01 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *stack);
void	set_targets_in_b(t_stack *a, t_stack *b);
void	set_targets_in_a(t_stack *a, t_stack *b);
void	calc_costs(t_stack *a, t_stack *b);
t_node	*find_cheapest(t_stack *a);
void	exec_move(t_stack *a, t_stack *b, t_node *cheapest, t_config *cfg);

static void	push_all_to_b(t_stack *a, t_stack *b, t_config *cfg)
{
	t_node	*cheapest;

	while (a->size > 3 && b->size < 2)
		pb(a, b, cfg);
	while (a->size > 3)
	{
		set_positions(a);
		set_positions(b);
		set_targets_in_b(a, b);
		calc_costs(a, b);
		cheapest = find_cheapest(a);
		exec_move(a, b, cheapest, cfg);
	}
}

static void	push_back_one(t_stack *a, t_stack *b, t_config *cfg)
{
	int	target;

	target = b->top->target;
	if (target <= a->size / 2)
	{
		while (target-- > 0)
			ra(a, cfg);
	}
	else
	{
		target = a->size - target;
		while (target-- > 0)
			rra(a, cfg);
	}
	pa(a, b, cfg);
}

static void	push_all_to_a(t_stack *a, t_stack *b, t_config *cfg)
{
	while (b->size > 0)
	{
		set_positions(a);
		set_positions(b);
		set_targets_in_a(a, b);
		push_back_one(a, b, cfg);
	}
}

void	sort_complex(t_stack *a, t_stack *b, t_config *cfg)
{
	int	min_pos;

	push_all_to_b(a, b, cfg);
	sort_three(a, cfg);
	push_all_to_a(a, b, cfg);
	set_positions(a);
	min_pos = find_node_pos(a, stack_min(a)->index);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a, cfg);
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a, cfg);
	}
}
