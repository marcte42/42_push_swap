/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:51:57 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 12:50:04 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	eval_same_dirrection(t_ps *ps, int a_index, int b_index)
{
	int	rra_i;
	int	rrb_i;
	int	rr_i;
	int	rrr_i;

	rr_i = ft_min(a_index, b_index);
	rra_i = ft_lstsize(ps->a_lst) - a_index;
	rrb_i = ft_lstsize(ps->b_lst) - b_index;
	rrr_i = ft_min(rra_i, rrb_i);
	if ((rr_i + a_index - rr_i + b_index - rr_i)
		<= (rrr_i + rra_i - rrr_i + rrb_i - rrr_i))
		return (rr_i + a_index - rr_i + b_index - rr_i);
	return (rrr_i + rra_i - rrr_i + rrb_i - rrr_i);
}

int	eval_opposite_dirrection(t_ps *ps, int a_index, int b_index)
{
	int	rra_i;
	int	rrb_i;

	rra_i = ft_lstsize(ps->a_lst) - a_index;
	rrb_i = ft_lstsize(ps->b_lst) - b_index;
	if (b_index + rra_i <= a_index + rrb_i)
		return (b_index + rra_i);
	return (a_index + rrb_i);
}

int	eval(t_ps *ps, t_list *node)
{
	int		a_index;
	int		b_index;
	int		eval_same;
	int		eval_opposite;

	b_index = get_node_index(ps->b_lst, node);
	a_index = get_node_index(ps->a_lst, get_relative_node(ps->a_lst, node));
	eval_same = eval_same_dirrection(ps, a_index, b_index);
	eval_opposite = eval_opposite_dirrection(ps, a_index, b_index);
	if (eval_same <= eval_opposite)
		return (eval_same);
	return (eval_opposite);
}
