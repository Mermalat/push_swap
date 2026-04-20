/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:12 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 19:00:13 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_top(t_stack *a, t_config *cfg)
{
	int	pos;
	int	size;

	pos = find_node_pos(a, stack_min(a)->index);
	size = a->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, cfg);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, cfg);
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_config *cfg)
{
	int	total;

	total = a->size;
	while (a->size > 0)
	{
		rotate_min_top(a, cfg);
		pb(a, b, cfg);
	}
	while (total-- > 0)
		pa(a, b, cfg);
}
