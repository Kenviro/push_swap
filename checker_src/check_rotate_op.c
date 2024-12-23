/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/23 13:40:29 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	top = *stack;
	*stack = top->next;
	top->next = NULL;
	ps_lstlast(*stack)->next = top;
}

void	check_ra(t_stacks *stacks)
{
	if (!stacks || !(stacks->stack_a))
		return ;
	rotate(&(stacks->stack_a));
}

void	check_rb(t_stacks *stacks)
{
	if (!stacks || !(stacks->stack_b))
		return ;
	rotate(&(stacks->stack_b));
}

void	check_rr(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate(&(stacks->stack_a));
	rotate(&(stacks->stack_b));
}
