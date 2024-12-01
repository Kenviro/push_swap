/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:02:28 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/01 15:00:37 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_stacks *stacks)
{
	t_list	*temp;

	temp = stacks->stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	ft_putstr_fd("OK\n", 1);
	exit(0);
}

void	arg_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_error(char **argv, t_stacks *stacks)
{
	if (check_arg(argv) == 1)
		arg_error();
	if (max_min_test(argv) == 1)
		arg_error();
	if (double_number(argv) == 1)
		arg_error();
	parse_arg(argv, stacks);
}

void	string_check(char **argv, t_stacks *stacks)
{
	if (check_char(argv) == 1)
		arg_error();
	if (double_number_string(argv) == 1)
		arg_error();
	if (max_min_test_string(argv) == 1)
		arg_error();
	parse_string(argv, stacks);
}

void	sort_small(t_stacks *stacks)
{
	if (stacks->size_a == 2)
	{
		sa(stacks);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	// else if (stacks->size_a == 5)
	// 	sort_five(stacks);
}
