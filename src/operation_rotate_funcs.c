/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:20:18 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 17:20:19 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack *a, t_config *cfg)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RA]++;
}

void	rb(t_stack *b, t_config *cfg)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RB]++;
}

void	rr(t_stack *a, t_stack *b, t_config *cfg)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_RR]++;
}
