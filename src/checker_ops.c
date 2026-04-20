#include "push_swap.h"
#include <stddef.h>
void	swap_silent(t_stack *stack)
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

void	push_silent(t_stack *dst, t_stack *src)
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

void	rotate_silent(t_stack *stack)
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

void	rev_rotate_silent(t_stack *stack)
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
