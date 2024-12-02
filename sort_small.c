/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:48:03 by kilian            #+#    #+#             */
/*   Updated: 2024/12/02 10:14:40 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack)
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

void	sort_three(t_stacks *stacks)
{
	if (stacks->stack_a->content > stacks->stack_a->next->content)
		sa(stacks);
	else
		rra(stacks);
}

void	sort_four(t_stacks *stacks)
{
	int		min;
	t_stack	*temp;

	min = find_min(stacks->stack_a);
	temp = stacks->stack_a;
	if (temp->content == min)
		pb(stacks);
	else if (temp->next->content == min)
	{
		sa(stacks);
		pb(stacks);
	}
	else if (temp->next->next->content == min)
	{
		rra(stacks);
		pb(stacks);
	}
	else
	{
		ra(stacks);
		pb(stacks);
	}
	sort_three(stacks);
	pa(stacks);
}
