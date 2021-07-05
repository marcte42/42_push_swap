/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:54:56 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 12:43:38 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_valid_int(char *n)
{
	size_t		i;
	long int	nb;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i++]))
			return (0);
	}
	nb = ft_atol(n);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

int	is_double_int(char **tab, int index, int size)
{
	char	*nb;

	nb = tab[index++];
	while (index < size)
	{
		if (ft_atoi(nb) == ft_atoi(tab[index]))
			return (0);
		index++;
	}
	return (1);
}

int	tab_to_list(t_list **head, char **tab, int size)
{
	int		i;
	int		*data;
	t_list	*node;

	if (!size)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!is_valid_int(tab[i]) || !is_double_int(tab, i, size))
			return (0);
		data = malloc(sizeof(int));
		if (!data)
			return (0);
		*data = ft_atoi(tab[i]);
		node = ft_lstnew(data);
		if (!node)
			return (0);
		ft_lstadd_back(head, node);
	}
	return (1);
}
