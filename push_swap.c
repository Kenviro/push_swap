/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:19:38 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/13 14:53:44 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		string_check(argv, stacks);
	else
		check_error(argv, stacks);
	index_stack(stacks);
	if (stacks->size_a <= 4)
		sort_small(stacks);
	// else
	// 	sort_big(stacks);
	// while (stacks->stack_a)
	// {
	// 	ft_printf("%d ", stacks->stack_a->content);
	// 	stacks->stack_a = stacks->stack_a->next;
	// }
	// ft_printf("\n");
	// ft_printf("Number of operations: %d\n", stacks->nbr_op);
	ps_lstclear(&stacks->stack_a);
	ps_lstclear(&stacks->stack_b);
	free(stacks);
	return (0);
}
