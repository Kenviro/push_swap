/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:20 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/23 13:40:35 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sa(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		temp2 = stacks->stack_a->index;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = temp;
		stacks->stack_a->index = stacks->stack_a->next->index;
		stacks->stack_a->next->index = temp2;
	}
}

void	check_sb(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		temp2 = stacks->stack_b->index;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = temp;
		stacks->stack_b->index = stacks->stack_b->next->index;
		stacks->stack_b->next->index = temp2;
	}
}

void	check_ss(t_stacks *stacks)
{
	check_sa(stacks);
	check_sb(stacks);
}
