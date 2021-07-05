/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:53:01 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/05/23 09:53:23 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstjoin(t_list *a_head, t_list *b_head)
{
	if (!a_head)
		return (b_head);
	ft_lstlast(a_head)->next = b_head;
	return (a_head);
}