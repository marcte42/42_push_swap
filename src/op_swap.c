/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:35:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 15:42:35 by mterkhoy         ###   ########.fr       */
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
		exit_routine("Malloc failed", ps);
	node = ft_lstnew(opcode);
	if (!node)
		exit_routine("Malloc failed", ps);
	ft_lstadd_back(&ps->op_lst, node);
}
