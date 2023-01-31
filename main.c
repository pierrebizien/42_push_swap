/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:01:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 13:14:16 by pbizien          ###   ########.fr       */
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

t_elem	*ft_generate_a_l(char **av, int ac, t_data *data)
{
	t_elem	*begin;
	t_elem	*tmp_l;
	int 	i;
	
	begin = ft_lst_new(ft_atoi(av[1]), 1);
	tmp_l = begin;
	i = 2;
	while (i < ac)
	{
		begin->next = ft_lst_new(ft_atoi(av[i]), i);
		begin = begin->next;
		i++;
	}
	begin = NULL;
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
	t_data	data;
	t_elem	*begin_a;
	t_elem	*begin_b;

	begin_b = NULL;
	data.ac = ac;
	data.thres = 25;
	if (data.thres == 0)
		data.thres = 1;
	begin_a = ft_generate_a_l(av, ac, &data);
	data.median = ft_median(begin_a, ac); 
	data.size = ft_lst_size(begin_a);
	ft_gen_index(&begin_a, &data);
	if(ac == 3)
		return (ft_two(&begin_a), 0);
	if (ac == 4)
		return (ft_three(&begin_a), 0);
	if (ac == 5)
		return (ft_four(&begin_a, &begin_b, &data), 0); 
	if (ac == 6)
		return (ft_five(&begin_a, &begin_b, &data), 0);
	if (ac < 500)
		return (ft_hundred(&begin_a, &begin_b, &data),  0);
	
	ft_hundred(&begin_a, &begin_b, &data);
	return (0);
}
