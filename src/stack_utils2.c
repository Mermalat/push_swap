/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:24:18 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 15:24:19 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_node_pos(t_stack *stack, int index)
{
	t_node	*cur;
	int		pos;

	cur = stack->top;
	pos = 0;
	while (cur)
	{
		if (cur->index == index)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

t_node	*get_node_at(t_stack *stack, int pos)
{
	t_node	*cur;
	int		i;

	cur = stack->top;
	i = 0;
	while (cur && i < pos)
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}
