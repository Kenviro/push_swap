/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:24 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/03 10:55:42 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	temp = stacks->stack_a->content;
	ps_lstdelone(stacks->stack_a);
	while (stacks->stack_a->prev)
		stacks->stack_a = stacks->stack_a->prev;
	ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
	stacks->nbr_op++;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b->content;
	ps_lstdelone(stacks->stack_b);
	while (stacks->stack_b->prev)
		stacks->stack_b = stacks->stack_b->prev;
	ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
	stacks->nbr_op++;
	ft_printf("rrb\n");
}

static void	copy_rra(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	temp = stacks->stack_a->content;
	ps_lstdelone(stacks->stack_a);
	while (stacks->stack_a->prev)
		stacks->stack_a = stacks->stack_a->prev;
	ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
}

static void	copy_rrb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b->content;
	ps_lstdelone(stacks->stack_b);
	while (stacks->stack_b->prev)
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
