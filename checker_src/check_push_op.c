/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/23 13:40:18 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_pa(t_stacks *stacks)
{
	t_stack	*temp_node;

	if (stacks->size_b == 0)
		return ;
	temp_node = stacks->stack_b->next;
	stacks->stack_b->next = stacks->stack_a;
	stacks->stack_a = stacks->stack_b;
	stacks->stack_b = temp_node;
	stacks->size_a++;
	stacks->size_b--;
}

void	check_pb(t_stacks *stacks)
{
	t_stack	*temp_node;

	if (stacks->size_a == 0)
		return ;
	temp_node = stacks->stack_a->next;
	stacks->stack_a->next = stacks->stack_b;
	stacks->stack_b = stacks->stack_a;
	stacks->stack_a = temp_node;
	stacks->size_b++;
	stacks->size_a--;
}
