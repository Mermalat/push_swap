#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
