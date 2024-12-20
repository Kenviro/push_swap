/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:24 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/19 15:01:59 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	stacks->nbr_op++;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_b));
	stacks->nbr_op++;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&(stacks->stack_a));
	reverse_rotate(&(stacks->stack_b));
	ft_printf("rrr\n");
}
