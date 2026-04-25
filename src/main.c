/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:18:33 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 18:18:34 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_config(t_config *cfg)
{
	int	i;

	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench = 0;
	cfg->op_count = 0;
	cfg->disorder = 0.0f;
	i = 0;
	while (i < 11)
		cfg->op_stats[i++] = 0;
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
	init_config(&cfg);
	parse_args(ac, av, &a, &cfg);
	if (a.size == 0)
		return (0);
	assign_indices(&a);
	sort_dispatch(&a, &b, &cfg);
	if (cfg.bench)
		print_bench(&cfg);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
