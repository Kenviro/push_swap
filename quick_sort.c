/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:59:44 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/18 15:04:35 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stacks *stacks, t_data *data)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = stacks->size_b;
	while (ps_lstsize(stacks->stack_b) && i < size_b)
	{
		if (stacks->stack_b->index == data->min)
			next_min(stacks, data);
		else if (stacks->stack_b->index >= data->middle)
		{
			stacks->stack_b->process = data->flag;
			pa(stacks);
		}
		else if (stacks->stack_b->index < data->middle)
			rb(stacks);
		i++;
	}
	data->max = data->middle;
	data->middle = (data->max - data->min) / 2 + data->min;
	data->flag++;
}

static void	sort_b(t_stacks *stacks, t_data *data)
{
	int	tmp_flag;

	tmp_flag = stacks->stack_a->process;
	if (stacks->stack_a->process != 0)
	{
		while (stacks->stack_a->process == tmp_flag)
		{
			if (stacks->stack_a->index != data->min)
				pb(stacks);
			next_min(stacks, data);
		}
	}
	else if (stacks->stack_a->process == 0)
	{
		while (stacks->stack_a->process != -1)
		{
			if (stacks->stack_a->index != data->min)
				pb(stacks);
			next_min(stacks, data);
		}
	}
	if (ps_lstsize(stacks->stack_b))
		data->max = (search_max(&stacks->stack_b))->index;
	data->middle = (data->max - data->min) / 2 + data-> min;
}

void	next_min(t_stacks *stacks, t_data *data)
{
	if (ps_lstsize(stacks->stack_b) > 0 && (stacks->stack_b->index == data->min))
		pa(stacks);
	else if (stacks->stack_a->index == data->min)
	{
		stacks->stack_a->process = -1;
		ra(stacks);
		data->min++;
	}
	else if ((ps_lstsize(stacks->stack_b)) > 2
		&& ps_lstlast(stacks->stack_b)->index == data->min)
		rrb(stacks);
	else if (stacks->stack_a->next->index == data->min)
		sa(stacks);
	else if ((ps_lstsize(stacks->stack_a)) > 1
		&& (stacks->stack_a->next->index == data->min)
		&& (stacks->stack_b->next->index == data->min + 1))
		ss(stacks);
	else
		return ;
	next_min(stacks, data);
}

static void	quick_start(t_stacks *stacks, t_data *data, int size_a)
{
	int	i;

	i = -1;
	while (i++ < size_a)
	{
		if (stacks->stack_a->index <= data->middle)
			pb(stacks);
		else
		{
			if (ps_lstsize(stacks->stack_b) > 1
				&& stacks->stack_b->index < data->middle / 2)
				rr(stacks);
			else
				ra(stacks);
		}
	}
	data->max = data->middle;
	data->middle = (data->max - data->min) / 2 + data->min;
	data->flag++;
}

void	quick_sort(t_stacks *stacks)
{
	t_data	data;

	data.min = search_min(&stacks->stack_a)->index;
	data.max = search_max(&stacks->stack_a)->index;
	data.middle = data.max / 2 + data.min;
	data.flag = 0;
	quick_start(stacks, &data, stacks->size_a);
	while (!(check_stack_a(stacks->stack_a, stacks->size_a)))
	{
		if (stacks->size_b == 0)
			sort_b(stacks, &data);
		else
			sort_a(stacks, &data);
	}
}
