/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 14:02:52 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!(ps->b_lst))
		return ;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = ps->a_lst;
	ps->a_lst = tmp;
	opcode = ft_strdup("pa");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	pb(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!(ps->a_lst))
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = ps->b_lst;
	ps->b_lst = tmp;
	opcode = ft_strdup("pb");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	sa(t_ps *ps)
{
	int		*tmp;
	char	*opcode;
	t_list	*node;

	if (!(ps->a_lst) || !ps->a_lst->next)
		return ;
	tmp = (ps->a_lst->content);
	ps->a_lst->content = ps->a_lst->next->content;
	ps->a_lst->next->content = tmp;
	opcode = ft_strdup("sa");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	ra(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst->next)
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->a_lst)->next = tmp;
	opcode = ft_strdup("ra");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rb(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->b_lst->next)
		return ;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->b_lst)->next = tmp;
	opcode = ft_strdup("rb");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rr(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst->next || !ps->b_lst->next)
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->a_lst)->next = tmp;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->a_lst)->next = tmp;
	opcode = ft_strdup("rr");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

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
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
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
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rrr(t_ps *ps)
{
	t_list	*tmp;
	t_list	*tmp_list;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst->next || !ps->b_lst->next)
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
	tmp_list = ps->b_lst;
	while (tmp_list->next)
	{
		tmp = tmp_list;
		tmp_list = tmp_list->next;
	}
	ft_lstlast(ps->b_lst)->next = ps->b_lst;
	ps->b_lst = tmp->next;
	tmp->next = NULL;
	opcode = ft_strdup("rrr");
	if (!opcode)
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
