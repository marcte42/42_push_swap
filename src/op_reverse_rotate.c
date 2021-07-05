/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 17:49:27 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_ps *ps)
{
	t_list	*tmp;
	t_list	*tmp_list;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst->next)
		return ;
	tmp_list = ps->a_lst;
	while (tmp_list->next)
	{
		tmp = tmp_list;
		tmp_list = tmp_list->next;
	}
	ft_lstlast(ps->a_lst)->next = ps->a_lst;
	ps->a_lst = tmp->next;
	tmp->next = NULL;
	opcode = ft_strdup("rra");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rrb(t_ps *ps)
{
	t_list	*tmp;
	t_list	*tmp_list;
	char	*opcode;
	t_list	*node;

	if (!ps->b_lst->next)
		return ;
	tmp_list = ps->b_lst;
	while (tmp_list->next)
	{
		tmp = tmp_list;
		tmp_list = tmp_list->next;
	}
	ft_lstlast(ps->b_lst)->next = ps->b_lst;
	ps->b_lst = tmp->next;
	tmp->next = NULL;
	opcode = ft_strdup("rrb");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	reverserotate_a(t_ps *ps)
{
	t_list	*tmp;
	t_list	*tmp_list;

	if (!ps->a_lst->next)
		return ;
	tmp_list = ps->a_lst;
	while (tmp_list->next)
	{
		tmp = tmp_list;
		tmp_list = tmp_list->next;
	}
	ft_lstlast(ps->a_lst)->next = ps->a_lst;
	ps->a_lst = tmp->next;
	tmp->next = NULL;
}

void	reverserotate_b(t_ps *ps)
{
	t_list	*tmp;
	t_list	*tmp_list;

	if (!ps->b_lst->next)
		return ;
	tmp_list = ps->b_lst;
	while (tmp_list->next)
	{
		tmp = tmp_list;
		tmp_list = tmp_list->next;
	}
	ft_lstlast(ps->b_lst)->next = ps->b_lst;
	ps->b_lst = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_ps *ps)
{
	char	*opcode;
	t_list	*node;

	reverserotate_a(ps);
	reverserotate_b(ps);
	opcode = ft_strdup("rrr");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
