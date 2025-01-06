/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:19:38 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/06 14:35:34 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker2(t_stacks *stacks, char *line)
{
	if (ft_strncmp(line, "ra", 3) == 0)
		check_ra(stacks);
	else if (ft_strncmp(line, "rb", 3) == 0)
		check_rb(stacks);
	else if (ft_strncmp(line, "rr", 3) == 0)
		check_rr(stacks);
	else if (ft_strncmp(line, "rra", 4) == 0)
		check_rra(stacks);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		check_rrb(stacks);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		check_rrr(stacks);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(line);
		free_stacks(stacks);
		exit(1);
	}
}

static void	checker(t_stacks *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, "sa", 3) == 0)
			check_sa(stacks);
		else if (ft_strncmp(line, "sb", 3) == 0)
			check_sb(stacks);
		else if (ft_strncmp(line, "ss", 3) == 0)
			check_ss(stacks);
		else if (ft_strncmp(line, "pa", 3) == 0)
			check_pa(stacks);
		else if (ft_strncmp(line, "pb", 3) == 0)
			check_pb(stacks);
		else
			checker2(stacks, line);
		free(line);
	}
	free(line);
}

static int	sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
	checker(stacks);
	if (sorted(stacks->stack_a) == 1 && stacks->size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
