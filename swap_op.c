/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:20 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/19 14:52:50 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		temp2 = stacks->stack_a->index;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = temp;
		stacks->stack_a->index = stacks->stack_a->next->index;
		stacks->stack_a->next->index = temp2;
		stacks->nbr_op++;
		ft_printf("sa\n");
	}
}

void	sb(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		temp2 = stacks->stack_b->index;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = temp;
		stacks->stack_b->index = stacks->stack_b->next->index;
		stacks->stack_b->next->index = temp2;
		stacks->nbr_op++;
		ft_printf("sb\n");
	}
}

static void	copy_sa(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		temp2 = stacks->stack_a->index;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = temp;
		stacks->stack_a->index = stacks->stack_a->next->index;
		stacks->stack_a->next->index = temp2;
	}
}

static void	copy_sb(t_stacks *stacks)
{
	int	temp;
	int	temp2;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		temp2 = stacks->stack_b->index;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = temp;
		stacks->stack_b->index = stacks->stack_b->next->index;
		stacks->stack_b->next->index = temp2;
	}
}

void	ss(t_stacks *stacks)
{
	copy_sa(stacks);
	copy_sb(stacks);
	stacks->nbr_op++;
	ft_printf("ss\n");
}
