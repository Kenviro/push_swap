/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:20 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/03 10:57:07 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = temp;
		stacks->nbr_op++;
		ft_printf("sa\n");
	}
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = temp;
		stacks->nbr_op++;
		ft_printf("sb\n");
	}
}

static void	copy_sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->content;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = temp;
	}
}

static void	copy_sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->content;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = temp;
	}
}

void	ss(t_stacks *stacks)
{
	copy_sa(stacks);
	copy_sb(stacks);
	stacks->nbr_op++;
	ft_printf("ss\n");
}
