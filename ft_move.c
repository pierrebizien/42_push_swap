/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:14 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/30 18:31:10 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_sa(t_elem **list_a, int ss)
{
    t_elem  *begin;
    int     tmp;
	
	if (!(*list_a) || !(*list_a)->next)
		return ;
    begin = *list_a;
    tmp = begin->val;
    begin->val = begin->next->val;
    begin->next->val = tmp;	
	if (ss == 0)
		ft_printf("sa\n");
}

void    ft_sb(t_elem **list_b, int ss)
{
    t_elem  *begin;
    int     tmp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
    begin = *list_b;
    tmp = begin->val;
    begin->val = begin->next->val;
    begin->next->val = tmp;
	if (ss == 0)
		ft_printf("sb\n");
}

void    ft_ss(t_elem **list_a, t_elem **list_b)
{
    ft_sa(list_a, 1);
    ft_sb(list_b, 1);
	ft_printf("ss\n");
}

void	ft_pb(t_elem **list_a, t_elem **list_b)
{
    t_elem	*tmp_a;
    
    if (!list_a)
        return ;
    tmp_a = (*list_a)->next;
	if (list_b)
		(*list_a)->next = *list_b;
	else
		(*list_a)->next = NULL;
	*list_b = *list_a;
	*list_a = tmp_a;
	ft_printf("pb\n");
}

void	ft_pa(t_elem **list_a, t_elem **list_b)
{
    t_elem	*tmp_a;
    
    if (!(*list_b))
        return ;
    tmp_a = (*list_b)->next;
	if (list_a)
		(*list_b)->next = *list_a;
	else
		(*list_b)->next = NULL;
	*list_a = *list_b;
	*list_b = tmp_a;
	ft_printf("pa\n");
}