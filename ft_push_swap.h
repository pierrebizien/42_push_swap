/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:58:32 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 14:30:11 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "gnl/get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

typedef struct  s_data
{
    int size;
    int median;
    int quart;
    int ac;
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
int	ft_lst_size(t_elem *list_a);
int ft_find_best_min(t_elem *list_a);


//---------------MOVEMENTS-----------------

void	ft_pa(t_elem **list_a, t_elem **list_b);
void	ft_pb(t_elem **list_a, t_elem **list_b);
void    ft_sa(t_elem **list_a, int ss);
void    ft_ss(t_elem **list_a, t_elem **list_b);
void    ft_sb(t_elem **list_b, int ss);
void	ft_ra(t_elem **list_a, int rr);
void	ft_rb(t_elem **list_b, int rr);
void	ft_rra(t_elem **list_a, int rrr);
void	ft_rrb(t_elem **list_b, int rrr);
void	ft_rrr(t_elem **list_a, t_elem **list_b);

int	ft_median(t_elem *list_a, int ac);

void ft_separate(t_elem **list_a, t_elem **list_b, t_data *data);

void	ft_two(t_elem **list_a);
void	ft_three(t_elem **list_a);
void	ft_four(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_five(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_5_to_19(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_gen_index(t_elem **list_a, t_data *data);


void	ft_ten(t_elem **list_a, t_elem **list_b, t_data *data);

int	ft_quart(t_elem *list_a, int ac);

#endif