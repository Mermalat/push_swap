/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:19:43 by memalli           #+#    #+#             */
/*   Updated: 2026/04/20 19:02:06 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define STRAT_ADAPTIVE  0
# define STRAT_SIMPLE    1
# define STRAT_MEDIUM    2
# define STRAT_COMPLEX   3

# define OP_SA   0
# define OP_SB   1
# define OP_SS   2
# define OP_PA   3
# define OP_PB   4
# define OP_RA   5
# define OP_RB   6
# define OP_RR   7
# define OP_RRA  8
# define OP_RRB  9
# define OP_RRR  10

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_config
{
	int		strategy;
	int		bench;
	int		op_count;
	int		op_stats[11];
	float	disorder;
}	t_config;

void	init_stack(t_stack *stack);
void	push_bottom(t_stack *stack, int value);
void	assign_indices(t_stack *a);

int		stack_size(t_stack *stack);
t_node	*stack_min(t_stack *stack);
t_node	*stack_max(t_stack *stack);
int		is_sorted(t_stack *a);
int		find_node_pos(t_stack *stack, int index);
t_node	*get_node_at(t_stack *stack, int pos);

void	parse_args(int ac, char **av, t_stack *a, t_config *cfg);

void	free_stack(t_stack *stack);
void	free_split(char **split);
void	error_exit(t_stack *a, t_stack *b);

void	sa(t_stack *a, t_config *cfg);
void	sb(t_stack *b, t_config *cfg);
void	ss(t_stack *a, t_stack *b, t_config *cfg);
void	pa(t_stack *a, t_stack *b, t_config *cfg);
void	pb(t_stack *a, t_stack *b, t_config *cfg);
void	ra(t_stack *a, t_config *cfg);
void	rb(t_stack *b, t_config *cfg);
void	rr(t_stack *a, t_stack *b, t_config *cfg);
void	rra(t_stack *a, t_config *cfg);
void	rrb(t_stack *b, t_config *cfg);
void	rrr(t_stack *a, t_stack *b, t_config *cfg);

void	sort_two(t_stack *a, t_config *cfg);
void	sort_three(t_stack *a, t_config *cfg);
void	sort_four(t_stack *a, t_stack *b, t_config *cfg);
void	sort_five(t_stack *a, t_stack *b, t_config *cfg);
void	sort_simple(t_stack *a, t_stack *b, t_config *cfg);
void	sort_medium(t_stack *a, t_stack *b, t_config *cfg);
void	sort_complex(t_stack *a, t_stack *b, t_config *cfg);

float	calc_disorder(t_stack *a);
void	sort_dispatch(t_stack *a, t_stack *b, t_config *cfg);

void	print_bench(t_config *cfg);

#endif
