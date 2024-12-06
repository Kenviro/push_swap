/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:40:22 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/02 16:00:15 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
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

// lst.c
void	ps_lstclear(t_stack **lst);
void	ps_lstdelone(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
void	ps_lstadd_back(t_stack **lst, t_stack *new);

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