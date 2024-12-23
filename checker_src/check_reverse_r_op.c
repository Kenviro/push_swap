/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reverse_r_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:24 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/23 13:40:24 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	last = ps_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	last->next = tmp;
	(*stack)->next = NULL;
	*stack = last;
}

void	check_rra(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
}

void	check_rrb(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_b));
}

void	check_rrr(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
}
