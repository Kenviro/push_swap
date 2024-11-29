/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/29 14:12:55 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*temp;

	if (stacks->size_b > 0)
	{
		temp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		temp->next = stacks->stack_a;
		stacks->stack_a = temp;
		stacks->size_a++;
		stacks->size_b--;
	}
}

void	pb(t_stacks *stacks)
{
	t_stack	*temp;

	if (stacks->size_a > 0)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		temp->next = stacks->stack_b;
		stacks->stack_b = temp;
		stacks->size_b++;
		stacks->size_a--;
	}
}
