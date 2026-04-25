/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:09 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 19:00:10 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk_size(int n);
int	find_max_pos(t_stack *b);

static int	try_push_top(t_stack *a, t_stack *b, int *range, t_config *cfg)
{
	int	mid;

	mid = (range[0] + range[1]) / 2;
	if (a->top->index >= range[0] && a->top->index < range[1])
	{
		pb(a, b, cfg);
		if (b->top->index < mid)
			rb(b, cfg);
		return (1);
	}
	return (0);
}

static void	push_one_chunk(t_stack *a, t_stack *b, int *range, t_config *cfg)
{
	int	count;
	int	target;

	target = range[1] - range[0];
	count = 0;
	while (count < target && a->size > 0)
	{
		if (try_push_top(a, b, range, cfg))
			count++;
		else
			ra(a, cfg);
	}
}

static void	push_max_back(t_stack *a, t_stack *b, t_config *cfg)
{
	int	pos;
	int	size;

	while (b->size > 0)
	{
		pos = find_max_pos(b);
		size = b->size;
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, cfg);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, cfg);
		}
		pa(a, b, cfg);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_config *cfg)
{
	int	chunk;
	int	n;
	int	range[2];

	n = a->size;
	chunk = calc_chunk_size(n);
	range[0] = 0;
	while (range[0] < n)
	{
		range[1] = range[0] + chunk;
		if (range[1] > n)
			range[1] = n;
		push_one_chunk(a, b, range, cfg);
		range[0] = range[1];
	}
	push_max_back(a, b, cfg);
}
