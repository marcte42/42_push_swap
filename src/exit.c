/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:03:41 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 17:58:15 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void	exit_routine(char *err, t_ps *ps)
{
	ft_lstfree(ps->a_lst);
	ft_lstfree(ps->b_lst);
	ft_lstfree(ps->op_lst);
	if (err)
	{
		ft_putstr_fd(err, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	exit(0);
}
