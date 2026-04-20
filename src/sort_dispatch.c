/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:19:05 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 18:19:06 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_by_size(t_stack *a, t_stack *b, t_config *cfg)
{
	if (a->size <= 1 || is_sorted(a))
		return (1);
	if (a->size == 2)
		sort_two(a, cfg);
	else if (a->size == 3)
		sort_three(a, cfg);
	else if (a->size == 4)
		sort_four(a, b, cfg);
	else if (a->size == 5)
		sort_five(a, b, cfg);
	else
		return (0);
	return (1);
}

static void	run_strategy(t_stack *a, t_stack *b, t_config *cfg)
{
	if (cfg->strategy == STRAT_SIMPLE)
		sort_simple(a, b, cfg);
	else if (cfg->strategy == STRAT_MEDIUM)
		sort_medium(a, b, cfg);
	else
		sort_complex(a, b, cfg);
}

static void	adaptive_select(t_config *cfg, float disorder)
{
	if (disorder < 0.2f)
		cfg->strategy = STRAT_SIMPLE;
	else if (disorder < 0.5f)
		cfg->strategy = STRAT_MEDIUM;
	else
		cfg->strategy = STRAT_COMPLEX;
}

void	sort_dispatch(t_stack *a, t_stack *b, t_config *cfg)
{
	float	disorder;

	if (sort_by_size(a, b, cfg))
		return ;
	disorder = calc_disorder(a);
	cfg->disorder = disorder;
	if (cfg->strategy == STRAT_ADAPTIVE)
		adaptive_select(cfg, disorder);
	run_strategy(a, b, cfg);
}
