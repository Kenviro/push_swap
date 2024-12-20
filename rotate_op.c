/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:51 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stacks *stacks)
{
	if (!stacks || !(stacks->stack_a))
		return ;
	rotate(&(stacks->stack_a));
	stacks->nbr_op++;
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	if (!stacks || !(stacks->stack_b))
		return ;
	rotate(&(stacks->stack_b));
	stacks->nbr_op++;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate(&(stacks->stack_a));
	rotate(&(stacks->stack_b));
	stacks->nbr_op++;
	ft_printf("rr\n");
}
