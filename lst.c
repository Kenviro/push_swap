/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:45:44 by ktintim-          #+#    #+#             */
/*   Updated: 2024/12/18 17:24:53 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ps_lstdelone(*lst);
		*lst = temp;
	}
}

void	ps_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(lst);
}

t_stack	*ps_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->content = content;
	new_node->index = -1;
	new_node->process = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}
