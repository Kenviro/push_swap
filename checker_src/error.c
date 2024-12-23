/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:02:28 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/23 13:53:54 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		ps_lstclear(&(stacks->stack_a));
		ps_lstclear(&(stacks->stack_b));
		free(stacks);
	}
}

void	is_sorted(t_stacks *stacks)
{
	t_stack	*temp;

	temp = stacks->stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	free_stacks(stacks);
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