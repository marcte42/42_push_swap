/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/11 18:08:11 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->a_lst || !ps->a_lst->next)
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->a_lst)->next = tmp;
	opcode = ft_strdup("ra");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rb(t_ps *ps)
{
	t_list	*tmp;
	char	*opcode;
	t_list	*node;

	if (!ps->b_lst || !ps->b_lst->next)
		return ;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->b_lst)->next = tmp;
	opcode = ft_strdup("rb");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	rotate_a(t_ps *ps)
{
	t_list	*tmp;

	if (!ps->a_lst || !ps->a_lst->next)
		return ;
	tmp = ps->a_lst;
	ps->a_lst = ps->a_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->a_lst)->next = tmp;
}

void	rotate_b(t_ps *ps)
{
	t_list	*tmp;

	if (!ps->b_lst || !ps->b_lst->next)
		return ;
	tmp = ps->b_lst;
	ps->b_lst = ps->b_lst->next;
	tmp->next = NULL;
	ft_lstlast(ps->b_lst)->next = tmp;
}

void	rr(t_ps *ps)
{
	char	*opcode;
	t_list	*node;

	rotate_a(ps);
	rotate_b(ps);
	opcode = ft_strdup("rr");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
