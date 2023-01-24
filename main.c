/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:01:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 13:54:24 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	ft_len_tmp(char **tmp)
{
	int	i;
	
	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

t_elem	*ft_generate_a_l(char *av, t_data *data)
{
	char	**tmp;
	t_elem	*begin;
	t_elem	*tmp_l;
	int 	i;
	
	i = 1;
	tmp = ft_split(av, ' ');
	begin = ft_lst_new(ft_atoi(tmp[0]), 0);
	tmp_l = begin;
	while (tmp[i])
	{
		begin->next = ft_lst_new(ft_atoi(tmp[i]), i);
		begin = begin->next;
		i++;
	}
	begin->next = NULL;
	data->size = i;
	return (tmp_l);
}

t_elem	*ft_generate_b_l(void)
{
	t_elem *begin;

	begin = ft_lst_new_empty();
	begin->next = NULL;
	return (begin);
}

int main(int ac, char **av)
{
    // int		*tab_a;
	// int		*tab_b;
	t_data	data;
	t_elem	*begin_a;
	t_elem	*begin_b;

	begin_a = ft_generate_a_l(av[1], &data);
	begin_b = NULL;
    (void)ac;
	ft_print_a_b(begin_a, begin_b);
	// begin_a = begin_a->next;
}
