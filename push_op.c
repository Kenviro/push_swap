/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/22 21:17:39 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
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
	stacks->nbr_op++;
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
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
	stacks->nbr_op++;
	ft_printf("pb\n");
}
