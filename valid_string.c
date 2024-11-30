/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/30 14:00:09 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == 45 || argv[1][i] == 43 || argv[1][i] == 32)
			i++;
		else if (argv[1][i] < 48 || argv[1][i] > 57)
			return (1);
		else
			i++;
	}
	return (0);
}

int double_number_string(char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			i++;
			continue;
		}
		num1 = ft_atoi(&argv[1][i]);
		while (argv[1][i] && argv[1][i] != ' ')
			i++;
		j = i;
		while (argv[1][j])
		{
			if (argv[1][j] == ' ')
			{
				j++;
				continue;
			}
			num2 = ft_atoi(&argv[1][j]);
			if (num1 == num2)
				return (1);
			while (argv[1][j] && argv[1][j] != ' ')
				j++;
		}
	}
	return (0);
}

static long int	ft_atoi_str(char *str)
{
	int			i;
	int			negative;
	long int	result;

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
			if (negative == -1)
				return (INT_MIN);
			return (INT_MAX);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

int	max_min_test_string(char **argv)
{
	int	i;
	long num;

	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '-' || argv[1][i] == '+')
			i++;
		num = ft_atoi_str(&argv[1][i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		while (argv[1][i] == ' ')
			i++;
	}
	return (0);
}
