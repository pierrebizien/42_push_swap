/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:01:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 17:37:05 by pbizien          ###   ########.fr       */
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

int	ft_check_same(t_elem *list)
{
	t_elem *tmp;

	tmp = list;
	while (tmp)
	{
		list = tmp->next;
		while (list)
		{
			if (list->val == tmp->val)
				return (0);
			list = list->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_free(t_elem *begin)
{
	t_elem *tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

t_elem	*ft_generate_a_l(char **av, int ac, t_data *data)
{
	t_elem	*begin;
	t_elem	*tmp_l;
	int 	i;
	
	if (ft_atoi(av[1]) == 3147483648)
		return (NULL);
	begin = ft_lst_new(ft_atoi(av[1]), 1);
	tmp_l = begin;
	i = 2;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == 3147483648)
			return (ft_free(tmp_l), NULL);
		begin->next = ft_lst_new(ft_atoi(av[i]), i);
		begin = begin->next;
		i++;
	}
	if (!ft_check_same(tmp_l))
	{
		ft_free(tmp_l);
		return (NULL);
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
	int		i;

	if (ac == 1 || (ac == 2 && ft_atoi(av[1]) == 3147483648))
		return (write(2, "Error\n", 6), -1);
	if (ac == 2)
		return (0);
	begin_b = NULL;
	data.info_b.count = 0;
	data.hid = 0;
	data.ac = ac;
	begin_a = ft_generate_a_l(av, ac, &data);
	if (!begin_a)
		return (write(2, "Error\n", 6), -1);
	data.median = ft_median(begin_a, ac);
	data.size = ft_lst_size(begin_a);
	ft_gen_index(&begin_a, &data);
	if (ft_is_sorted(begin_a))
		return (ft_free(begin_a), 0);
	if(ac == 3)
		return (ft_two(&begin_a, &data), ft_free(begin_a), 0);
	if (ac == 4)
		return (ft_three(&begin_a, &data), ft_free(begin_a), 0);
	if (ac == 5)
		return (ft_four(&begin_a, &begin_b, &data), ft_free(begin_a), 0); 
	if (ac == 6)
		return (ft_five(&begin_a, &begin_b, &data), ft_free(begin_a), 0);
	i = 2;
	data.info_b.bcount = -1;
	ft_free(begin_a);
	while (i < 50)
	{
		data.thres = i;
		begin_a = ft_generate_a_l(av, ac, &data);
		data.size = ft_lst_size(begin_a);
		ft_gen_index(&begin_a, &data);
		ft_hundred_hid(&begin_a, &begin_b, &data);
		if (data.info_b.count < data.info_b.bcount || data.info_b.bcount == -1)
		{
			data.info_b.bcount = data.info_b.count;
			data.info_b.bloc = i;
		}
		ft_free(begin_a);
		data.info_b.count = 0;
		i++;
	}
	data.thres = data.info_b.bloc;
	begin_a = ft_generate_a_l(av, ac, &data);
	data.median = ft_median(begin_a, ac); 
	data.size = ft_lst_size(begin_a);
	ft_gen_index(&begin_a, &data);
	ft_hundred(&begin_a, &begin_b, &data);
	ft_free(begin_a);
	return (0);
}
