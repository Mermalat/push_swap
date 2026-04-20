#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	swap_silent(t_stack *stack);
void	push_silent(t_stack *dst, t_stack *src);
void	rotate_silent(t_stack *stack);
void	rev_rotate_silent(t_stack *stack);

static char	*read_line(void)
{
	char	buf[2];
	char	*line;
	char	*tmp;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	buf[1] = '\0';
	while (read(0, buf, 1) > 0)
	{
		if (buf[0] == '\n')
			return (line);
		tmp = ft_strjoin(line, buf);
		free(line);
		if (!tmp)
			return (NULL);
		line = tmp;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static int	exec_op_1(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_silent(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap_silent(b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_silent(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_silent(b);
	else if (ft_strcmp(line, "rra") == 0)
		rev_rotate_silent(a);
	else if (ft_strcmp(line, "rrb") == 0)
		rev_rotate_silent(b);
	else
		return (0);
	return (1);
}

static int	exec_op_2(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "ss") == 0)
	{
		swap_silent(a);
		swap_silent(b);
	}
	else if (ft_strcmp(line, "pa") == 0)
		push_silent(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		push_silent(b, a);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate_silent(a);
		rotate_silent(b);
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		rev_rotate_silent(a);
		rev_rotate_silent(b);
	}
	else
		return (0);
	return (1);
}

static void	run_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = read_line();
	while (line)
	{
		if (!exec_op_1(line, a, b) && !exec_op_2(line, a, b))
		{
			free(line);
			error_exit(a, b);
		}
		free(line);
		line = read_line();
	}
	if (is_sorted(a) && b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;

	if (ac < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	cfg.strategy = STRAT_ADAPTIVE;
	cfg.bench = 0;
	cfg.op_count = 0;
	parse_args(ac, av, &a, &cfg);
	if (a.size == 0)
		return (0);
	assign_indices(&a);
	run_checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
