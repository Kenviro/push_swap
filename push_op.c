/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/20 15:37:38 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_lstnew(int content, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->content = content;
	new_node->index = index;
	new_node->process = 0;
	new_node->next = NULL;
	return (new_node);
}

void	pa(t_stacks *stacks)
{
	t_stack	*temp_node;

	if (stacks->size_b > 0)
	{
		temp_node = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		if (stacks->stack_b)
			stacks->stack_b->prev = NULL;
		ps_lstadd_front(&stacks->stack_a, push_lstnew(temp_node->content, temp_node->index));
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
		ps_lstadd_front(&stacks->stack_b, push_lstnew(temp_node->content, temp_node->index));
		free(temp_node);
		stacks->size_b++;
		stacks->size_a--;
		stacks->nbr_op++;
		ft_printf("pb\n");
	}
}
