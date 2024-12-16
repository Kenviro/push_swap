/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/16 17:39:51 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] == 45 || argv[1][i] == 43 || argv[1][i] == 32) && \
				argv[1][i + 1] != '\0')
			i++;
		else if (argv[1][i] < 48 || argv[1][i] > 57)
			return (1);
		else
			i++;
	}
	return (0);
}

int	double_number_string(char **argv)
{
	int	index[2];
	int	num1;
	int	num2;

	index[0] = -1;
	while (argv[1][index[0]])
	{
		if (argv[1][index[0]++] == ' ')
			continue ;
		num1 = ft_atoi(&argv[1][index[0]]);
		while (argv[1][index[0]] && argv[1][index[0]] != ' ')
			index[0]++;
		index[1] = index[0] - 1;
		while (argv[1][index[1]])
		{
			if (argv[1][index[1]++] == ' ')
				continue ;
			num2 = ft_atoi(&argv[1][index[1]]);
			if (num1 == num2)
				return (1);
			while (argv[1][index[1]++] && argv[1][index[1]] != ' ')
				index[1]++;
		}
	}
	return (0);
}

static int	ft_atoi_str(char *str, int *out, int *index)
{
	int		i;
	int		negative;
	long	result;

	result = 0;
	negative = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * negative > INT_MAX || result * negative < INT_MIN)
			return (1);
		i++;
	}
	*out = (int)(result * negative);
	*index += i;
	return (0);
}

int	max_min_test_string(char **argv)
{
	int	i;
	int	num;

	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			break ;
		if (ft_atoi_str(&argv[1][i], &num, &i))
			return (1);
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] != '\0' && (argv[1][i] < '0' || argv[1][i] > '9') && \
			argv[1][i] != '+' && argv[1][i] != '-')
			return (1);
	}
	return (0);
}
