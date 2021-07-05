/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:55:09 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 15:48:07 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_ps
{
	t_list		*a_lst;
	t_list		*b_lst;
	t_list		*op_lst;
}				t_ps;

int				tab_to_list(t_list **head, char **tab, int size);
void			exit_routine(char *err, t_ps *ps);
void			sort_3(t_ps *ps);
void			sort_5(t_ps *ps);
void			sort(t_ps *ps);
void			optimal_solution(t_ps *ps);

void			pa(t_ps *ps);
void			pb(t_ps *ps);
void			sa(t_ps *ps);
void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);
void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);

t_list			*get_min_node(t_list *head);
int				get_node_index(t_list *head, t_list *node);
t_list			*get_optimal_node(t_ps *ps);
t_list			*get_relative_node(t_list *head_a, t_list *node);

int				eval(t_ps *ps, t_list *node);
int				eval_opposite_dirrection(t_ps *ps, int a_index, int b_index);
int				eval_same_dirrection(t_ps *ps, int a_index, int b_index);

/*
** Operations
*/

#endif
