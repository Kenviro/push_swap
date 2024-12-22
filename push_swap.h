/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:40:22 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/22 21:45:48 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_data
{
	int		min;
	int		max;
	int		middle;
	int		flag;
}	t_data;
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

// lst.c
void	ps_lstclear(t_stack **lst);
void	ps_lstdelone(t_stack *lst);
t_stack	*ps_lstnew(int content);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
void	ps_lstadd_back(t_stack **lst, t_stack *new);

void	free_stacks(t_stacks *stacks);
void	index_stack(t_stacks *stacks);
void	check_error(char **argv, t_stacks *stacks);
void	arg_error(void);
void	string_check(char **argv, t_stacks *stacks);
void	parse_string(char **argv, t_stacks *stacks);
void	parse_arg(char **argv, t_stacks *stacks);
void	sort_small(t_stacks *stacks);
void	is_sorted(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	five_sort(t_stacks	*stacks);
void	quick_sort(t_stacks *stacks, t_stack **stack_a, \
			t_stack **stack_b);
int		check_stack_a(t_stack **stack_a, int size_a);
int		check_sort(t_stack *stack);
int		check_reverse_sort(t_stacks *table);
int		ps_lstsize(t_stack *lst);
t_stack	*search_min(t_stack **stack);
t_stack	*search_max(t_stack **stack);
t_stack	*ps_lstlast(t_stack *lst);

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