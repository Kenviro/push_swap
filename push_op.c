/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/05 15:45:50 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*temp_node;

	if (stacks->size_b > 0)
	{
		temp_node = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		if (stacks->stack_b)
			stacks->stack_b->prev = NULL;
		ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp_node->content));
		free(temp_node);
		stacks->size_a++;
		stacks->size_b--;
		stacks->nbr_op++;
		ft_printf("pa\n");
	}
}


void	pb(t_stacks *stacks)
{
	t_stack	*temp_node;

	if (stacks->size_a > 0)
	{
		temp_node = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		if (stacks->stack_a)
			stacks->stack_a->prev = NULL;
		ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp_node->content));
		free(temp_node);
		stacks->size_b++;
		stacks->size_a--;
		stacks->nbr_op++;
		ft_printf("pb\n");
	}
}
