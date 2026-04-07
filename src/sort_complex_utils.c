#include "push_swap.h"

void	set_positions(t_stack *stack)
{
	t_node	*cur;
	int		i;

	cur = stack->top;
	i = 0;
	while (cur)
	{
		cur->pos = i;
		cur = cur->next;
		i++;
	}
}

int	is_above_median(t_stack *stack, t_node *node)
{
	return (node->pos <= stack->size / 2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	min_of(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max_of(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
