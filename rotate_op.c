/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/29 14:21:19 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		last = stacks->stack_a;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void	rb(t_stacks *stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		last = stacks->stack_b;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}