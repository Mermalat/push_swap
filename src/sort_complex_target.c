#include "push_swap.h"

void	set_targets_in_b(t_stack *a, t_stack *b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		best_idx;

	cur_a = a->top;
	while (cur_a)
	{
		best_idx = -1;
		cur_b = b->top;
		while (cur_b)
		{
			if (cur_b->index < cur_a->index)
			{
				if (best_idx == -1 || cur_b->index > best_idx)
					best_idx = cur_b->index;
			}
			cur_b = cur_b->next;
		}
		if (best_idx == -1)
			cur_a->target = stack_max(b)->pos;
		else
			cur_a->target = find_node_pos(b, best_idx);
		cur_a = cur_a->next;
	}
}

void	set_targets_in_a(t_stack *a, t_stack *b)
{
	t_node	*cur_b;
	t_node	*cur_a;
	int		best_idx;

	cur_b = b->top;
	while (cur_b)
	{
		best_idx = -1;
		cur_a = a->top;
		while (cur_a)
		{
			if (cur_a->index > cur_b->index)
			{
				if (best_idx == -1 || cur_a->index < best_idx)
					best_idx = cur_a->index;
			}
			cur_a = cur_a->next;
		}
		if (best_idx == -1)
			cur_b->target = stack_min(a)->pos;
		else
			cur_b->target = find_node_pos(a, best_idx);
		cur_b = cur_b->next;
	}
}
