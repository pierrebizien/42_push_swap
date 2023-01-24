/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:58:32 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 13:52:28 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "gnl/get_next_line.h"
#include "ft_printf.h"
#include "libft.h"


typedef struct  s_data
{
    int size;
    int median;
}               t_data;

typedef struct  s_elem
{
    int ind;
    int val;
    struct s_elem  *next;
    struct s_elem  *previous;
}               t_elem;

t_elem	*ft_lst_new(int content, int index);
void    ft_print_a_b(t_elem *list_a, t_elem *list_b);
t_elem  *ft_lst_new_empty(void);


#endif