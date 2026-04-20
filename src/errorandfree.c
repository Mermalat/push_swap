/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorandfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:14:41 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 16:14:42 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	error_exit(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
