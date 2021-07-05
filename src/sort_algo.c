/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:51:57 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 14:00:40 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	same_direction_sort_rr(t_ps *ps, int a_index, int b_index)
{
	int		rr_i;
	int		tmp;

	rr_i = ft_min(a_index, b_index);
	tmp = rr_i;
	while (tmp--)
		rr(ps);
	while (a_index - rr_i)
	{
		ra(ps);
		a_index--;
	}
	while (b_index - rr_i)
	{
		rb(ps);
		b_index--;
	}
}

void	same_direction_sort_rrr(t_ps *ps, int a_index, int b_index)
{
	int		rrr_i;
	int		rra_i;
	int		rrb_i;
	int		tmp;

	rra_i = ft_lstsize(ps->a_lst) - a_index;
	rrb_i = ft_lstsize(ps->b_lst) - b_index;
	rrr_i = ft_min(rra_i, rrb_i);
	tmp = rrr_i;
	while (tmp--)
		rrr(ps);
	while (rra_i-- - rrr_i)
		rra(ps);
	while (rrb_i-- - rrr_i)
		rrb(ps);
}

void	same_direction_sort(t_ps *ps, int a_index, int b_index)
{
	int		rra_i;
	int		rrb_i;
	int		rr_i;
	int		rrr_i;

	rr_i = ft_min(a_index, b_index);
	rra_i = ft_lstsize(ps->a_lst) - a_index;
	rrb_i = ft_lstsize(ps->b_lst) - b_index;
	rrr_i = ft_min(rra_i, rrb_i);
	if ((rr_i + a_index - rr_i + b_index - rr_i)
		<= (rrr_i + rra_i - rrr_i + rrb_i - rrr_i))
	{
		same_direction_sort_rr(ps, a_index, b_index);
		return ;
	}
	same_direction_sort_rrr(ps, a_index, b_index);
}

void	opposite_direction_sort(t_ps *ps, int a_index, int b_index)
{
	int		rra_i;
	int		rrb_i;

	rra_i = ft_lstsize(ps->a_lst) - a_index;
	rrb_i = ft_lstsize(ps->b_lst) - b_index;
	if (b_index + rra <= a_index + rrb)
	{
		while (b_index--)
			rb(ps);
		while (rra_i--)
			rra(ps);
		return ;
	}	
	while (a_index--)
		ra(ps);
	while (rrb_i--)
		rrb(ps);
}

void	optimal_solution(t_ps *ps)
{
	t_list	*optimal_node;
	t_list	*relative_node;
	int		optimal_index;
	int		relative_index;

	optimal_node = get_optimal_node(ps);
	relative_node = get_relative_node(ps->a_lst, optimal_node);
	optimal_index = get_node_index(ps->b_lst, optimal_node);
	relative_index = get_node_index(ps->a_lst, relative_node);
	if (eval_same_dirrection(ps, relative_index, optimal_index)
		<= eval_opposite_dirrection(ps, relative_index, optimal_index))
		{
			same_direction_sort(ps, relative_index, optimal_index);
		}
		
	else
	{
		opposite_direction_sort(ps, relative_index, optimal_index);
	}
}
