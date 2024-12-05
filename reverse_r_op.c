/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:24 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/05 14:16:12 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	t_stack	*last;
	int		temp;

	if (stacks->size_a < 2)
		return ;
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	last = stacks->stack_a;
	temp = last->content;
	if (last->prev)
		last->prev->next = NULL;
	stacks->stack_a = last->prev;
	ps_lstdelone(last);
	while (stacks->stack_a && stacks->stack_a->prev)
		stacks->stack_a = stacks->stack_a->prev;
	ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
	stacks->nbr_op++;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	t_stack	*last;
	int		temp;

	if (stacks->size_b < 2)
		return ;
	while (stacks->stack_b->next)
		stacks->stack_b = stacks->stack_b->next;
	last = stacks->stack_b;
	temp = last->content;
	if (last->prev)
		last->prev->next = NULL;
	stacks->stack_b = last->prev;
	ps_lstdelone(last);
	while (stacks->stack_b && stacks->stack_b->prev)
		stacks->stack_b = stacks->stack_b->prev;
	ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
	stacks->nbr_op++;
	ft_printf("rrb\n");
}

static void	copy_rra(t_stacks *stacks)
{
	t_stack	*last;
	int		temp;

	if (stacks->size_a < 2)
		return ;
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	last = stacks->stack_a;
	temp = last->content;
	if (last->prev)
		last->prev->next = NULL;
	stacks->stack_a = last->prev;
	ps_lstdelone(last);
	while (stacks->stack_a && stacks->stack_a->prev)
		stacks->stack_a = stacks->stack_a->prev;
	ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
}

static void	copy_rrb(t_stacks *stacks)
{
	t_stack	*last;
	int		temp;

	if (stacks->size_b < 2)
		return ;
	while (stacks->stack_b->next)
		stacks->stack_b = stacks->stack_b->next;
	last = stacks->stack_b;
	temp = last->content;
	if (last->prev)
		last->prev->next = NULL;
	stacks->stack_b = last->prev;
	ps_lstdelone(last);
	while (stacks->stack_b && stacks->stack_b->prev)
		stacks->stack_b = stacks->stack_b->prev;
	ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
}

void	rrr(t_stacks *stacks)
{
	copy_rra(stacks);
	copy_rrb(stacks);
	stacks->nbr_op++;
	ft_printf("rrr\n");
}
