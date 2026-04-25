/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:18 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 19:00:19 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack *a, t_stack *b, t_config *cfg)
{
	int	min_pos;

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
	pb(a, b, cfg);
}

void	sort_four(t_stack *a, t_stack *b, t_config *cfg)
{
	push_min_to_b(a, b, cfg);
	sort_three(a, cfg);
	pa(a, b, cfg);
}

void	sort_five(t_stack *a, t_stack *b, t_config *cfg)
{
	push_min_to_b(a, b, cfg);
	push_min_to_b(a, b, cfg);
	sort_three(a, cfg);
	pa(a, b, cfg);
	pa(a, b, cfg);
}
