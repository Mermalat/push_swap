#include "push_swap.h"

static const char	*g_op_names[] = {
	"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};

static void	print_disorder(float disorder)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)(disorder * 10000) % 100;
	ft_putstr_fd("Disorder:  ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(int strategy)
{
	ft_putstr_fd("Strategy:  ", 2);
	if (strategy == STRAT_SIMPLE)
		ft_putstr_fd("simple (selection sort)\n", 2);
	else if (strategy == STRAT_MEDIUM)
		ft_putstr_fd("medium (chunk-based)\n", 2);
	else if (strategy == STRAT_COMPLEX)
		ft_putstr_fd("complex\n", 2);
	else
		ft_putstr_fd("adaptive\n", 2);
}

static void	print_op_breakdown(t_config *cfg)
{
	int	i;

	ft_putstr_fd("--- Operation Breakdown ---\n", 2);
	i = 0;
	while (i < 11)
	{
		if (cfg->op_stats[i] > 0)
		{
			ft_putstr_fd("  ", 2);
			ft_putstr_fd((char *)g_op_names[i], 2);
			ft_putstr_fd(": ", 2);
			ft_putnbr_fd(cfg->op_stats[i], 2);
			ft_putchar_fd('\n', 2);
		}
		i++;
	}
}

void	print_bench(t_config *cfg)
{
	ft_putstr_fd("\n=== Benchmark Results ===\n", 2);
	print_disorder(cfg->disorder);
	print_strategy(cfg->strategy);
	ft_putstr_fd("Total ops: ", 2);
	ft_putnbr_fd(cfg->op_count, 2);
	ft_putchar_fd('\n', 2);
	print_op_breakdown(cfg);
	ft_putstr_fd("=========================\n", 2);
}
