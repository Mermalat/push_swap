/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:20:16 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 17:20:17 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	rev_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, t_config *cfg)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RRA]++;
}

void	rrb(t_stack *b, t_config *cfg)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RRB]++;
}

void	rrr(t_stack *a, t_stack *b, t_config *cfg)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RRR]++;
}
