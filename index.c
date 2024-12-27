/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:10:35 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/27 13:19:10 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_indexed(t_stack *stack)
{
	while (stack)
	{
		if (stack->index == -1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	index_stack(t_stacks *stacks)
{
	t_stack	*temp;
	int		index;
	int		max;

	index = ps_lstsize(stacks->stack_a) - 1;
	while (is_indexed(stacks->stack_a) == 0)
	{
		temp = stacks->stack_a;
		max = INT_MIN;
		t_stack *max_node = NULL;
		while (temp)
		{
			if (temp->content > max && temp->index == -1)
			{
				max = temp->content;
				max_node = temp;
			}
			temp = temp->next;
		}
		if (max_node)
			max_node->index = index;

		index--;
	}
}


t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
