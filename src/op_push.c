/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:20:20 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 17:20:21 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src->top)
		return ;
	node = src->top;
	src->top = node->next;
	src->size--;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, t_config *cfg)
{
	push_top(a, b);
	ft_putstr_fd("pa\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_PA]++;
}

void	pb(t_stack *a, t_stack *b, t_config *cfg)
{
	push_top(b, a);
	ft_putstr_fd("pb\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_PB]++;
}
