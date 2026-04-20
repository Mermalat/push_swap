/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:39:34 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 17:24:21 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

t_node	*stack_min(t_stack *stack)
{
	t_node	*cur;
	t_node	*min;

	if (!stack->top)
		return (NULL);
	cur = stack->top;
	min = cur;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*stack_max(t_stack *stack)
{
	t_node	*cur;
	t_node	*max;

	if (!stack->top)
		return (NULL);
	cur = stack->top;
	max = cur;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a->top)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}
