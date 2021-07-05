/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:55:17 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 17:49:44 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd((char *)lst->content, 0);
        ft_putstr_fd("\n", 0);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	ft_bzero(&ps, sizeof(ps));
	if (!tab_to_list(&ps.a_lst, &av[1], ac - 1))
		exit_routine("Error", &ps);
	if (ft_lstsize(ps.a_lst) <= 3)
		sort_3(&ps);
	else if (ft_lstsize(ps.a_lst) <= 5)
		sort_5(&ps);
	else
		sort(&ps);
	ft_printlst(ps.op_lst);
	exit_routine(NULL, &ps);
	return (0);
}
