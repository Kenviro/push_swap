/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:20:05 by kilian            #+#    #+#             */
/*   Updated: 2024/12/22 21:36:27 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_string(char **argv, t_stacks *stacks)
{
	int		i;
	int		num;
	t_stack	*new;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			i++;
			continue ;
		}
		num = ft_atoi(&argv[1][i]);
		new = ps_lstnew(num);
		ps_lstadd_back(&stacks->stack_a, new);
		stacks->size_a++;
		while (argv[1][i] && argv[1][i] != ' ')
			i++;
	}
	is_sorted(stacks);
}

void	parse_arg(char **argv, t_stacks *stacks)
{
	int		i;
	int		num;
	t_stack	*new;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		new = ps_lstnew(num);
		ps_lstadd_back(&stacks->stack_a, new);
		stacks->size_a++;
		i++;
	}
	is_sorted(stacks);
}
