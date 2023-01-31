/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:58:32 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 18:32:08 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "gnl/get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

typedef struct  s_best
{
    int bcount;
    int count;
    int bloc;
    
}               t_best;


typedef struct  s_data
{
    int size;
    int median;
    int med_ind;
    int quart;
    int     ac;
    int     thres;
    t_best  info_b;
	int	hid;
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

void	ft_pa(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_pb(t_elem **list_a, t_elem **list_b, t_data *data);
void    ft_sa(t_elem **list_a, t_data *data);
void    ft_ss(t_elem **list_a, t_elem **list_b, t_data *data);
void    ft_sb(t_elem **list_b, t_data *data);
void	ft_ra(t_elem **list_a, t_data *data);
void	ft_rb(t_elem **list_b, t_data *data);
void	ft_rra(t_elem **list_a, t_data *data);
void	ft_rrb(t_elem **list_b, t_data *data);
void	ft_rrr(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_loop_rra(t_elem **list_a, int nb, t_data *data);


int	ft_median(t_elem *list_a, int ac);
void	ft_med_ind(t_elem *list_a, t_data *data);

void ft_separate(t_elem **list_a, t_elem **list_b, t_data *data);

void	ft_two(t_elem **list_a, t_data *data);
void	ft_three(t_elem **list_a, t_data *data);
void	ft_four(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_five(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_5_to_19(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_gen_index(t_elem **list_a, t_data *data);
void	ft_hundred(t_elem **list_a, t_elem **list_b, t_data *data);
void	ft_hundred_hid(t_elem **list_a, t_elem **list_b, t_data *data);
int	ft_is_sorted(t_elem *list);

int	ft_len_tmp(char **tmp);
int	ft_check_same(t_elem *list);
void	ft_free(t_elem *begin);
t_elem	*ft_generate_a_l(char **av, int ac, t_data *data);

int ft_d_quotes(char **av, int ac);

void	ft_ten(t_elem **list_a, t_elem **list_b, t_data *data);

int	ft_quart(t_elem *list_a, int ac);

#endif