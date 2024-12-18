/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:59:44 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/18 18:35:38 by ktintim-         ###   ########.fr       */
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
	size_b = ps_lstsize(*stack_b);
	// printf("size_a : %d\n", stacks->size_a);
	// printf("size_b : %d\n", stacks->size_b);
	// printf("min : %d\n", data->min);
	// printf("max : %d\n", data->max);
	// printf("middle : %d\n", data->middle);
	while (ps_lstsize(*stack_b) && i < size_b)
	{
		// printf("i : %d\n", i);
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
	// data->middle = calculate_median(*stack_a, data->min, data->max);

	while (*stack_a)
	{
		if ((*stack_a)->index <= data->middle)
		{
			// printf("Pousser vers stack_b : index = %d\n", (*stack_a)->index);
			pb(stacks);
		}
		else
		{
			if (ps_lstsize(*stack_b) > 1 && (*stack_b)->index < data->middle / 2)
			{
				// printf("Double rotation (rr) : stack_a->index = %d, stack_b->index = %d\n",
					//    (*stack_a)->index, (*stack_b)->index);
				rr(stacks);
			}
			else
			{
				// printf("Rotation de stack_a (ra) : index = %d\n", (*stack_a)->index);
				ra(stacks);
			}
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

	data.min = search_min(stack_a)->index;
	data.max = search_max(stack_a)->index;
	data.middle = data.max / 2 + data.min;
	data.flag = 0;
	// printf("min : %d\n", data.min);
	// printf("max : %d\n", data.max);
	// printf("middle : %d\n", data.middle);
	// exit(0);
	quick_start(stacks, stack_a, stack_b, &data);
	// printf("size_a : %d\n", stacks->size_a);
	// printf("size_b : %d\n", stacks->size_b);
	// printf("min : %d\n", data.min);
	// printf("max : %d\n", data.max);
	// printf("middle : %d\n", data.middle);
	// exit(0);
	while (!(check_stack_a(stack_a, stacks->size_a)))
	{
		if (ps_lstsize(*stack_b) == 0)
			sort_b(stacks, stack_a, stack_b, &data);
		else
			sort_a(stacks, stack_a, stack_b, &data);
	}
}
