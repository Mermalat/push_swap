/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:20 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 19:00:21 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_config *cfg)
{
	if (a->top->index > a->top->next->index)
		sa(a, cfg);
}

void	sort_three(t_stack *a, t_config *cfg)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->index;
	mid = a->top->next->index;
	bot = a->top->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(a, cfg);
	else if (top > mid && mid > bot)
	{
		sa(a, cfg);
		rra(a, cfg);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, cfg);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, cfg);
		ra(a, cfg);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, cfg);
}
