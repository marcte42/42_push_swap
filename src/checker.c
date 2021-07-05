/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:05:12 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 19:01:20 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_list_sorted(t_list *head)
{
	int	*a;
	int	*b;

	while (head && head->next)
	{
		a = head->content;
		b = head->next->content;
		if (*a > *b)
			return (0);
		head = head->next;
	}
	return (1);
}

int	process_ops(char *opcode, t_ps *ps)
{
	if (ft_strcmp(opcode, "sa") == 0)
		sa(ps);
	if (ft_strcmp(opcode, "sb") == 0)
		sb(ps);
	else if (ft_strcmp(opcode, "pa") == 0)
		pa(ps);
	else if (ft_strcmp(opcode, "pb") == 0)
		pb(ps);
	else if (ft_strcmp(opcode, "ra") == 0)
		ra(ps);
	else if (ft_strcmp(opcode, "rb") == 0)
		rb(ps);
	else if (ft_strcmp(opcode, "rr") == 0)
		rr(ps);
	else if (ft_strcmp(opcode, "rra") == 0)
		rra(ps);
	else if (ft_strcmp(opcode, "rrb") == 0)
		rrb(ps);
	else if (ft_strcmp(opcode, "rrr") == 0)
		rrr(ps);
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_ps	ps;
	char	*opcode;

	if (ac == 1)
		return (0);
	ft_bzero(&ps, sizeof(ps));
	if (!tab_to_list(&ps.a_lst, &av[1], ac - 1))
		exit_routine("Error", &ps);
	while (get_next_line(0, &opcode))
	{
		if (!opcode)
			break ;
		if (process_ops(opcode, &ps) == -1)
			exit_routine("Error", &ps);
	}
	if (is_list_sorted(ps.a_lst) && ft_lstsize(ps.b_lst) == 0)
		exit_routine("OK", &ps);
	else
		exit_routine("KO", &ps);
	return (0);
}
