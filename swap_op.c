/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:20 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/01 15:02:01 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		temp->next = stacks->stack_a->next;
		stacks->stack_a->next = temp;
	}
}

void	sb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		temp->next = stacks->stack_b->next;
		stacks->stack_b->next = temp;
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
