/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:10:35 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/18 18:11:46 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_content(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

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
	int		i;

	index = 0;
	i = min_content(stacks->stack_a);
	temp = stacks->stack_a;
	while (1)
	{
		while (temp)
		{
			if (temp->content == i)
			{
				temp->index = index;
				// printf("content-index : %d-%d\n", temp->content, temp->index);
				index++;
			}
			temp = temp->next;
		}
		i++;
		temp = stacks->stack_a;
		if (is_indexed(stacks->stack_a) == 1)
			break ;
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
