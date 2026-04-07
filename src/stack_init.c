#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

static t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	push_bottom(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*cur;

	new = create_node(value);
	if (!new)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		cur = stack->top;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	stack->size++;
}

void	assign_indices(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
