/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:40:22 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/01 14:59:59 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

// typedef struct s_stack
// {
// 	int				content;
// 	struct s_stack	*next;
// }	t_stack;

typedef struct s_stacks
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			size_a;
	int			size_b;
}	t_stacks;

void	check_error(char **argv, t_stacks *stacks);
void	arg_error(void);
void	string_check(char **argv, t_stacks *stacks);
void	parse_string(char **argv, t_stacks *stacks);
void	parse_arg(char **argv, t_stacks *stacks);
void	sort_small(t_stacks *stacks);
void	is_sorted(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);

int		check_arg(char **argv);
int		check_char(char **argv);
int		double_number(char **argv);
int		max_min_test(char **argv);
int		double_number_string(char **argv);
int		max_min_test_string(char **argv);

// operations
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif