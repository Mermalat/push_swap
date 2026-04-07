#include "push_swap.h"

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
