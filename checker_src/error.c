/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:02:28 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/06 10:20:25 by ktintim-         ###   ########.fr       */
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

void	arg_error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stacks);
	exit(1);
}

void	check_error(char **argv, t_stacks *stacks)
{
	if (check_arg(argv) == 1)
		arg_error(stacks);
	if (max_min_test(argv) == 1)
		arg_error(stacks);
	if (double_number(argv) == 1)
		arg_error(stacks);
	parse_arg(argv, stacks);
}

void	string_check(char **argv, t_stacks *stacks)
{
	if (check_char(argv) == 1)
		arg_error(stacks);
	if (double_number_string(argv) == 1)
		arg_error(stacks);
	if (max_min_test_string(argv) == 1)
		arg_error(stacks);
	parse_string(argv, stacks);
}
