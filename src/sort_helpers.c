/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:51:57 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 15:36:47 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_node_index(t_list *head, t_list *node)
{
	int	i;

	i = 0;
	while (head != node)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_list	*get_min_node(t_list *head)
{
	int		*min;
	int		*curr;
	t_list	*min_node;

	min = head->content;
	min_node = head;
	while (head)
	{
		curr = head->content;
		if (*curr < *min)
		{
			min = curr;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

unsigned int	get_diff(t_list *head_a, t_list *node)
{
	int				*a;
	int				*b;
	unsigned int	diff;

	b = node->content;
	a = head_a->content;
	diff = *a - *b;
	if (*a > *b)
		return (diff);
	return (0);
}

t_list	*get_relative_node(t_list *head_a, t_list *node)
{
	t_list				*relative_node;
	t_list				*tmp;
	unsigned int		diff;
	unsigned int		min_diff;

	tmp = head_a;
	relative_node = tmp;
	min_diff = 4294967295;
	while (tmp)
	{
		diff = get_diff(tmp, node);
		if (diff > 0 && diff < min_diff)
		{
			relative_node = tmp;
			min_diff = diff;
		}
		tmp = tmp->next;
	}
	if (min_diff == 4294967295)
		return (get_min_node(head_a));
	return (relative_node);
}

t_list	*get_optimal_node(t_ps *ps)
{
	t_list	*tmp;
	int		curr_eval;
	int		min_eval;
	t_list	*optimal_node;

	tmp = ps->b_lst;
	optimal_node = tmp;
	min_eval = eval(ps, tmp);
	while (tmp)
	{
		curr_eval = eval(ps, tmp);
		if (curr_eval < min_eval)
		{
			min_eval = curr_eval;
			optimal_node = tmp;
		}
		tmp = tmp->next;
	}
	return (optimal_node);
}
