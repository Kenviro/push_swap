/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:59:44 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/20 16:12:43 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	next_min(t_stacks *stacks, t_stack **stack_a, t_stack **stack_b, \
					t_data *data);

static void	sort_a(t_stacks *stacks, t_stack **stack_a, \
			t_stack **stack_b, t_data *data)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = stacks->size_b;
	while (ps_lstsize(*stack_b) && i < size_b)
	{
		if ((*stack_b)->index == data->min)
			next_min(stacks, stack_a, stack_b, data);
		else if ((*stack_b)->index >= data->middle)
		{
			(*stack_b)->process = data->flag;
			pa(stacks);
		}
		else if ((*stack_b)->index < data->middle)
			rb(stacks);
		i++;
	}
	data->max = data->middle;
	data->middle = (data->max - data->min) / 2 + data->min;
	data->flag++;
}

static void	sort_b(t_stacks *stacks, t_stack **stack_a, \
			t_stack **stack_b, t_data *data)
{
	int	tmp_flag;

	tmp_flag = (*stack_a)->process;
	if ((*stack_a)->process != 0)
	{
		while ((*stack_a)->process == tmp_flag)
		{
			if ((*stack_a)->index != data->min)
				pb(stacks);
			next_min(stacks, stack_a, stack_b, data);
		}
	}
	else if ((*stack_a)->process == 0)
	{
		while ((*stack_a)->process != -1)
		{
			if ((*stack_a)->index != data->min)
				pb(stacks);
			next_min(stacks, stack_a, stack_b, data);
		}
	}
	if (ps_lstsize(*stack_b))
		data->max = (search_max(stack_b))->index;
	data->middle = (data->max - data->min) / 2 + data-> min;
}

static void	next_min(t_stacks *stacks, t_stack **stack_a, t_stack **stack_b,
	t_data *data)
{
	if (ps_lstsize(*stack_b) > 0 && \
				((*stack_b)->index == data->min))
		pa(stacks);
	else if ((*stack_a)->index == data->min)
	{
		(*stack_a)->process = -1;
		ra(stacks);
		data->min++;
	}
	else if ((ps_lstsize((*stack_b))) > 2
		&& ps_lstlast((*stack_b))->index == data->min)
		rrb(stacks);
	else if ((*stack_a)->next->index == data->min)
		sa(stacks);
	else if ((ps_lstsize(*stack_a)) > 1
		&& ((*stack_a)->next->index == data->min)
		&& ((*stack_b)->next->index == data->min + 1))
		ss(stacks);
	else
		return ;
	next_min(stacks, stack_a, stack_b, data);
}

static void	quick_start(t_stacks *stacks, t_stack **stack_a, t_stack **stack_b,
						t_data *data)
{
	int	i;
	int	size_a;

	i = -1;
	size_a = stacks->size_a;
	while (i++ < size_a)
	{
		if ((*stack_a)->index <= data->middle)
			pb(stacks);
		else
		{
			if (ps_lstsize(*stack_b) > 1 && \
					(*stack_b)->index < data->middle / 2)
				rr(stacks);
			else
				ra(stacks);
		}
	}
	data->max = data->middle;
	data->middle = (data->max - data->min) / 2 + data->min;
	data->flag++;
}

void	quick_sort(t_stacks *stacks, t_stack **stack_a, \
			t_stack **stack_b)
{
	t_data	data;
	int		size_a;

	size_a = stacks->size_a;
	data.min = search_min(stack_a)->index;
	data.max = search_max(stack_a)->index;
	data.middle = data.max / 2 + data.min;
	data.flag = 0;
	quick_start(stacks, stack_a, stack_b, &data);
	while ((check_stack_a(stack_a, size_a)) == 0)
	{
		if (ps_lstsize(*stack_b) == 0)
			sort_b(stacks, stack_a, stack_b, &data);
		else
			sort_a(stacks, stack_a, stack_b, &data);
	}
}
