/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 19:06:47 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	sb(t_ps *ps)
{
	int		*tmp;
	char	*opcode;
	t_list	*node;

	if (!(ps->b_lst) || !ps->b_lst->next)
		return ;
	tmp = (ps->b_lst->content);
	ps->b_lst->content = ps->b_lst->next->content;
	ps->b_lst->next->content = tmp;
	opcode = ft_strdup("sb");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}

void	swap_a(t_ps *ps)
{
	int		*tmp;

	if (!(ps->a_lst) || !ps->a_lst->next)
		return ;
	tmp = (ps->a_lst->content);
	ps->a_lst->content = ps->a_lst->next->content;
	ps->a_lst->next->content = tmp;
}

void	swap_b(t_ps *ps)
{
	int		*tmp;

	if (!(ps->b_lst) || !ps->b_lst->next)
		return ;
	tmp = (ps->b_lst->content);
	ps->b_lst->content = ps->b_lst->next->content;
	ps->b_lst->next->content = tmp;
}

void	sb(t_ps *ps)
{
	char	*opcode;
	t_list	*node;

	swap_a(ps);
	swap_b(ps);
	opcode = ft_strdup("ss");
	if (!opcode)
		exit_routine("Error", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Error", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
