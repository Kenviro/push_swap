/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:23:52 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/05 14:51:05 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][0] == 45 || argv[i][0] == 43) && argv[i][1] != '\0')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	double_number(char **argv)
{
	int	i;
	int	temp;

	i = 1;
	while (argv[i])
	{
		temp = i + 1;
		while (argv[temp])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[temp]))
				return (1);
			temp++;
		}
		i++;
	}
	return (0);
}

static int	int_min_max_test(char *str)
{
	int	i;
	int	negative;
	int	result;

	result = 0;
	negative = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (INT_MAX - (str[i] - '0')) / 10)
		{
			return (1);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (0);
}

int	max_min_test(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (int_min_max_test(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
