/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:20:27 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 17:20:28 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!stack->top || !stack->top->next)
		return ;
	tmp_val = stack->top->value;
	tmp_idx = stack->top->index;
	stack->top->value = stack->top->next->value;
	stack->top->index = stack->top->next->index;
	stack->top->next->value = tmp_val;
	stack->top->next->index = tmp_idx;
}

void	sa(t_stack *a, t_config *cfg)
{
	swap_top(a);
	ft_putstr_fd("sa\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_SA]++;
}

void	sb(t_stack *b, t_config *cfg)
{
	swap_top(b);
	ft_putstr_fd("sb\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_SB]++;
}

void	ss(t_stack *a, t_stack *b, t_config *cfg)
{
	swap_top(a);
	swap_top(b);
	ft_putstr_fd("ss\n", 1);
	cfg->op_count++;
	cfg->op_stats[OP_SS]++;
}
