/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:19:38 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/03 11:27:31 by ktintim-         ###   ########.fr       */
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
		arg_error();
	if (argc == 2)
		string_check(argv, stacks);
	else
		check_error(argv, stacks);
	if (stacks->size_a <= 4)
		sort_small(stacks);
	// else
	// 	sort_big(stacks);
	while (stacks->stack_a)
	{
		ft_printf("%d ", stacks->stack_a->content);
		stacks->stack_a = stacks->stack_a->next;
	}
	ft_printf("\n");
	ps_lstclear(&stacks->stack_a);
	ps_lstclear(&stacks->stack_b);
	free(stacks);
	ft_printf("Number of operations: %d\n", stacks->nbr_op);
	return (0);
}
