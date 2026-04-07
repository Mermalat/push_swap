#include "push_swap.h"

int	ft_abs(int n);
int	max_of(int a, int b);

static void	calc_cost_a(t_stack *a, t_node *node)
{
	if (node->pos <= a->size / 2)
		node->cost_a = node->pos;
	else
		node->cost_a = -(a->size - node->pos);
}

static void	calc_cost_b(t_stack *b, t_node *node)
{
	if (node->target <= b->size / 2)
		node->cost_b = node->target;
	else
		node->cost_b = -(b->size - node->target);
}

void	calc_costs(t_stack *a, t_stack *b)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		calc_cost_a(a, cur);
		calc_cost_b(b, cur);
		cur = cur->next;
	}
}

int	total_cost(t_node *node)
{
	int	ca;
	int	cb;

	ca = node->cost_a;
	cb = node->cost_b;
	if (ca >= 0 && cb >= 0)
		return (max_of(ca, cb));
	if (ca < 0 && cb < 0)
		return (max_of(ft_abs(ca), ft_abs(cb)));
	return (ft_abs(ca) + ft_abs(cb));
}

t_node	*find_cheapest(t_stack *a)
{
	t_node	*cur;
	t_node	*best;
	int		best_cost;
	int		cur_cost;

	cur = a->top;
	best = cur;
	best_cost = total_cost(cur);
	while (cur)
	{
		cur_cost = total_cost(cur);
		if (cur_cost < best_cost)
		{
			best = cur;
			best_cost = cur_cost;
		}
		cur = cur->next;
	}
	return (best);
}
