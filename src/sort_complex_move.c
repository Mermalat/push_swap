#include "push_swap.h"

int	ft_abs(int n);

static void	do_both_rot(t_stack *a, t_stack *b, t_node *n, t_config *cfg)
{
	int	ca;
	int	cb;

	ca = n->cost_a;
	cb = n->cost_b;
	while (ca > 0 && cb > 0)
	{
		rr(a, b, cfg);
		ca--;
		cb--;
	}
	while (ca-- > 0)
		ra(a, cfg);
	while (cb-- > 0)
		rb(b, cfg);
}

static void	do_both_revrot(t_stack *a, t_stack *b, t_node *n, t_config *cfg)
{
	int	ca;
	int	cb;

	ca = ft_abs(n->cost_a);
	cb = ft_abs(n->cost_b);
	while (ca > 0 && cb > 0)
	{
		rrr(a, b, cfg);
		ca--;
		cb--;
	}
	while (ca-- > 0)
		rra(a, cfg);
	while (cb-- > 0)
		rrb(b, cfg);
}

static void	do_mixed_rot(t_stack *a, t_stack *b, t_node *n, t_config *cfg)
{
	int	ca;
	int	cb;

	ca = n->cost_a;
	cb = n->cost_b;
	while (ca > 0 && ca--)
		ra(a, cfg);
	while (ca < 0 && ca++)
		rra(a, cfg);
	while (cb > 0 && cb--)
		rb(b, cfg);
	while (cb < 0 && cb++)
		rrb(b, cfg);
}

void	exec_move(t_stack *a, t_stack *b, t_node *cheapest, t_config *cfg)
{
	if (cheapest->cost_a >= 0 && cheapest->cost_b >= 0)
		do_both_rot(a, b, cheapest, cfg);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		do_both_revrot(a, b, cheapest, cfg);
	else
		do_mixed_rot(a, b, cheapest, cfg);
	pb(a, b, cfg);
}
