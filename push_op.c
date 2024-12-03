/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:57:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/03 10:56:25 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	int		temp;

	if (stacks->size_b > 0)
	{
		temp = stacks->stack_b->content;
		ps_lstdelone(stacks->stack_b);
		ps_lstadd_front(&stacks->stack_a, ps_lstnew(temp));
		stacks->size_a++;
		stacks->size_b--;
		stacks->nbr_op++;
		ft_printf("pa\n");
	}
}

void	pb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a > 0)
	{
		temp = stacks->stack_a->content;
		ps_lstdelone(stacks->stack_a);
		ps_lstadd_front(&stacks->stack_b, ps_lstnew(temp));
		stacks->size_b++;
		stacks->size_a--;
		stacks->nbr_op++;
		ft_printf("pb\n");
	}
}
