/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:02:28 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/26 15:46:21 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_error(char **argv)
{
	if (check_arg(argv) == 1)
		arg_error();
	if (max_min_test(argv) == 1)
		arg_error();
	if (double_number(argv) == 1)
		arg_error();
	ft_printf("OK\n");
}
