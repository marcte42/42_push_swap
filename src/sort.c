/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:13:38 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 16:40:47 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_cycle_sorted(t_list *head)
{
	int		*a;
	int		*b;
	t_list	*last;
	t_list	*lowest;
	int		size;

	if (!head || !head->next)
		return (1);
	size = ft_lstsize(head);
	lowest = get_min_node(head);
	last = ft_lstlast(head);
	last->next = head;
	while (--size)
	{
		a = lowest->content;
		b = lowest->next->content;
		if (*a > *b)
		{
			last->next = NULL;
			return (0);
		}
		lowest = lowest->next;
	}
	last->next = NULL;
	return (1);
}

void	smallest_to_top(t_ps *ps, t_list **head)
{
	int		lowest_index;
	int		size;

	size = ft_lstsize(*head);
	lowest_index = get_node_index(*head, get_min_node(*head));
	if (lowest_index <= size / 2)
	{
		while (lowest_index-- > 0)
			ra(ps);
	}
	else
	{
		while (lowest_index++ < size)
			rra(ps);
	}
}

void	sort_3(t_ps *ps)
{
	if (is_cycle_sorted(ps->a_lst))
	{
		smallest_to_top(ps, &ps->a_lst);
		return ;
	}
	sa(ps);
	smallest_to_top(ps, &ps->a_lst);
}

void	sort_5(t_ps *ps)
{
	int		size;

	if (is_cycle_sorted(ps->a_lst))
	{
		smallest_to_top(ps, &ps->a_lst);
		return ;
	}
    size = ft_lstsize(ps->a_lst);
	while (size-- > 3)
	{
		smallest_to_top(ps, &ps->a_lst);
		pb(ps);
	}
	sort_3(ps);
	while (ps->b_lst)
		pa(ps);
}

void	sort(t_ps *ps)
{
	int		i;

    if (is_cycle_sorted(ps->a_lst))
	{
		smallest_to_top(ps, &ps->a_lst);
		return ;
	}
	i = ft_lstsize(ps->a_lst);
	while (i-- > 3)
		pb(ps);
	sort_3(ps);
	while (ps->b_lst)
	{
		optimal_solution(ps);
		pa(ps);
	}
	smallest_to_top(ps, &ps->a_lst);
}
