/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:14 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 13:33:56 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_sa(t_elem *list_a)
{
    t_elem  *begin;
    int     tmp;

    begin = list_a;
    tmp = begin->val;
    begin->val = begin->next->val;
    begin->next->val = tmp;
}

void    ft_sb(t_elem *list_b)
{
    t_elem  *begin;
    int     tmp;

    begin = list_b;
    tmp = begin->val;
    begin->val = begin->next->val;
    begin->next->val = tmp;
}