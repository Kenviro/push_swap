/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:58:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/05 15:04:46 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_stack	*new;
	t_stack	*last;
	t_stack	*first;
	int		temp;

	if (stacks->size_a > 1)
	{
		first = stacks->stack_a;
		temp = first->content;
		stacks->stack_a = first->next;
		if (stacks->stack_a)
			stacks->stack_a->prev = NULL;
		free(first);
		last = stacks->stack_a;
		while (last && last->next)
			last = last->next;
		new = ps_lstnew(temp);
		if (last)
			last->next = new;
		new->prev = last;
		stacks->nbr_op++;
		ft_printf("ra\n");
	}
}


void	rb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		ps_lstdelone(stacks->stack_b);
		while (stacks->stack_b->next)
			stacks->stack_b = stacks->stack_b->next;
		ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
		stacks->nbr_op++;
		ft_printf("rb\n");
	}
}

static void	copy_ra(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		ps_lstdelone(stacks->stack_a);
		while (stacks->stack_a->next)
			stacks->stack_a = stacks->stack_a->next;
		ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
	}
}

static void	copy_rb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		ps_lstdelone(stacks->stack_b);
		while (stacks->stack_b->next)
			stacks->stack_b = stacks->stack_b->next;
		ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
	}
}

void	rr(t_stacks *stacks)
{
	copy_ra(stacks);
	copy_rb(stacks);
	stacks->nbr_op++;
	ft_printf("rr\n");
}
