/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:24 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/30 12:30:07 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stacks->stack_a;
	stacks->stack_a = last;
}

void	rrb(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stacks->stack_b;
	stacks->stack_b = last;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
