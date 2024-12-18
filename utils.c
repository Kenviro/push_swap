/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:31:25 by kilian            #+#    #+#             */
/*   Updated: 2024/12/18 17:17:01 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_reverse_sort(t_stacks *table)
{
	t_stack	*tmp;

	tmp = table->stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*search_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*search_max(t_stack **stack)
{
	t_stack	*max;
	t_stack	*tmp;

	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	check_stack_a(t_stack **stack_a, int size_a)
{
	int	length;

	length = ps_lstsize(*stack_a);
	if (length != size_a)
		return (0);
	if (check_sort(*stack_a) == 0)
		return (0);
	return (1);
}
