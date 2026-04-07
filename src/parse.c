#include "push_swap.h"

int		is_flag(const char *str);
int		is_valid_int(const char *str);
int		is_within_int(long value);

static int	has_duplicate(t_stack *a, int val)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == val)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static void	validate_and_add(char *str, t_stack *a, char **split)
{
	long	val;

	if (!is_valid_int(str))
	{
		free_split(split);
		error_exit(a, NULL);
	}
	val = ft_atoi(str);
	if (!is_within_int(val) || has_duplicate(a, (int)val))
	{
		free_split(split);
		error_exit(a, NULL);
	}
	push_bottom(a, (int)val);
}

static void	parse_flags(int ac, char **av, t_config *cfg)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--simple") == 0)
			cfg->strategy = STRAT_SIMPLE;
		else if (ft_strcmp(av[i], "--medium") == 0)
			cfg->strategy = STRAT_MEDIUM;
		else if (ft_strcmp(av[i], "--complex") == 0)
			cfg->strategy = STRAT_COMPLEX;
		else if (ft_strcmp(av[i], "--adaptive") == 0)
			cfg->strategy = STRAT_ADAPTIVE;
		else if (ft_strcmp(av[i], "--bench") == 0)
			cfg->bench = 1;
		i++;
	}
}

void	parse_args(int ac, char **av, t_stack *a, t_config *cfg)
{
	int		i;
	char	**split;
	int		j;

	parse_flags(ac, av, cfg);
	i = 1;
	while (i < ac)
	{
		if (is_flag(av[i]))
		{
			i++;
			continue ;
		}
		split = ft_split(av[i], ' ');
		if (!split)
			error_exit(a, NULL);
		j = 0;
		while (split[j])
		{
			validate_and_add(split[j], a, split);
			j++;
		}
		free_split(split);
		i++;
	}
}
