#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int	calc_chunk_size(int n)
{
	int	base;

	base = ft_sqrt(n);
	return (base + (base * 3 / 10));
}

int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max_idx;
	int		max_pos;
	int		pos;

	if (!b->top)
		return (0);
	cur = b->top;
	max_idx = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}
