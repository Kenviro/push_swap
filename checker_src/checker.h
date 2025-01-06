/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:16:58 by kilian            #+#    #+#             */
/*   Updated: 2025/01/06 10:20:03 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	int				index;
	int				process;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;
	int			size_b;
	int			nbr_op;
}	t_stacks;

// operation
void	check_pa(t_stacks *stacks);
void	check_pb(t_stacks *stacks);
void	check_sa(t_stacks *stacks);
void	check_sb(t_stacks *stacks);
void	check_ss(t_stacks *stacks);
void	check_ra(t_stacks *stacks);
void	check_rb(t_stacks *stacks);
void	check_rr(t_stacks *stacks);
void	check_rra(t_stacks *stacks);
void	check_rrb(t_stacks *stacks);
void	check_rrr(t_stacks *stacks);

// lst.c
void	ps_lstclear(t_stack **lst);
void	ps_lstdelone(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	ps_lstadd_front(t_stack **lst, t_stack *new_elem);
void	ps_lstadd_back(t_stack **lst, t_stack *new_elem);

// checker.c
void	free_stacks(t_stacks *stacks);
t_stack	*ps_lstlast(t_stack *lst);

// error.c
void	free_stacks(t_stacks *stacks);
void	string_check(char **argv, t_stacks *stacks);
void	check_error(char **argv, t_stacks *stacks);
void	arg_error(t_stacks *stacks);
void	is_sorted(t_stacks *stacks);

// valid_arg.c
int		check_arg(char **argv);
int		double_number(char **argv);
int		max_min_test(char **argv);

// valid_string.c
int		check_char(char **argv);
int		double_number_string(char **argv);
int		max_min_test_string(char **argv);

// parse.c
void	parse_string(char **argv, t_stacks *stacks);
void	parse_arg(char **argv, t_stacks *stacks);

#endif