/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:19:38 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/01 14:54:42 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	ft_bzero(&stacks, sizeof(t_stacks));
	if (argc == 1)
		arg_error();
	if (argc == 2)
		string_check(argv, stacks);
	else
		check_error(argv, stacks);
	if (stacks->size_a <= 5)
		sort_small(stacks);
	// else
	// 	sort_big(stacks);
}
