/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:35:10 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/30 13:32:27 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_print_a_b(t_elem *list_a, t_elem *list_b)
{
    t_elem  *begin_a;
    t_elem  *begin_b;
    
    begin_a = list_a;
    begin_b = list_b;
    ft_printf("----------\n");
    while (begin_a || begin_b)
    {
        if (!begin_a)
            ft_printf("A:\t\t| B:\t\t %d\n", begin_b->val);
        else if (!begin_b)
            ft_printf("A:\t%d\t| B:\t\t\n", begin_a->val);
        else
            ft_printf("A:\t%d\t| B:\t%d\t\n", begin_a->val, begin_b->val);
        if (begin_a)
            begin_a = begin_a->next;
        if (begin_b)
            begin_b = begin_b->next;
    }
    ft_printf("----------\n");
}
