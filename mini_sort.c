/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:19 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/20 16:56:06 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_stacks	*stacks)
{
	int	length;

	length = ps_lstsize(stacks->stack_a);
	while (length--)
	{
		if (stacks->stack_a->index == 0 || stacks->stack_a->index == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
	if (stacks->stack_a->content > stacks->stack_a->next->content)
		sa(stacks);
}
