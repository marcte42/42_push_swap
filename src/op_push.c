/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/11 18:09:02 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->b_lst)
		return ;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = ps->a_lst;
	ps->a_lst = tmp;
	opcode = ft_strdup("pa");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	pb(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst)
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = ps->b_lst;
	ps->b_lst = tmp;
	opcode = ft_strdup("pb");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
