/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:48:03 by kilian            #+#    #+#             */
/*   Updated: 2024/12/06 10:39:29 by ktintim-         ###   ########.fr       */
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
	{
		if (stacks->stack_a->content < stacks->stack_a->next->next->content)
			sa(stacks);
		else
		{
			ra(stacks);
			if (stacks->stack_a->content > stacks->stack_a->next->content)
				sa(stacks);
		}
		if (stacks->stack_a->next->content > \
				stacks->stack_a->next->next->content)
			rra(stacks);
	}
	else
	{
		rra(stacks);
		if (stacks->stack_a->content > stacks->stack_a->next->content)
			sa(stacks);
	}
}

void	sort_four(t_stacks *stacks)
{
	int		min;

	min = find_min(stacks->stack_a);
	if (stacks->stack_a->content == min)
		pb(stacks);
	else if (stacks->stack_a->next->content == min)
	{
		sa(stacks);
		pb(stacks);
	}
	else if (stacks->stack_a->next->next->content == min)
	{
		rra(stacks);
		rra(stacks);
		pb(stacks);
	}
	else
	{
		rra(stacks);
		pb(stacks);
	}
	sort_three(stacks);
	pa(stacks);
}
