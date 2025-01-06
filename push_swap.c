/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:19:38 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/06 10:47:09 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		ps_lstclear(&(stacks->stack_a));
		ps_lstclear(&(stacks->stack_b));
		free(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	if (argc == 1)
	{
		free(stacks);
		return (0);
	}
	if (argc == 2)
		string_check(argv, stacks);
	else
		check_error(argv, stacks);
	index_stack(stacks);
	if (stacks->size_a <= 4)
		sort_small(stacks);
	else if (stacks->size_a == 5)
		five_sort(stacks);
	else
		quick_sort(stacks, &stacks->stack_a, &stacks->stack_b);
	free_stacks(stacks);
	return (0);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ps_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (++i);
}
