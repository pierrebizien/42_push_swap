/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:36:41 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_b_loc_2(t_elem *list_a, t_data *data, int sens, int i)
{
	int	j;
	int	loc;
	int	gap;

	j = 0;
	loc = -1;
	(void)sens;
	(void)data;
	(void)i;
	gap = INT_MAX;
	while (list_a)
	{
		if (list_a->ind <= data->size / 2 && list_a->ind > \
			((data->size / 2) - (data->thres * i)))
		{
			if (ft_b_gap(list_a, j, data) < gap)
			{
				gap = ft_b_gap(list_a, j, data);
				loc = j + 1;
			}
		}
		list_a = list_a->next;
		j++;
	}
	return (loc);
}

int	ft_find_loc_2(t_elem **list_b, int index)
{
	t_elem	*tmp;
	int		i;

	i = 1;
	tmp = *list_b;
	while (tmp)
	{
		if (tmp->ind == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	ft_send_home(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	loc_h;

	i = data->size;
	while (i >= 1)
	{
		loc_h = ft_find_loc_2(list_b, i);
		while ((*list_b)->ind != i)
		{
			if ((*list_b)->ind == i - 1)
				ft_pa(list_a, list_b, data);
			else if (loc_h <= ft_lst_size(*list_b) / 2)
				ft_rb(list_b, data);
			else
				ft_rrb(list_b, data);
		}
		ft_pa(list_a, list_b, data);
		if ((*list_a)->next && (*list_a)->ind > (*list_a)->next->ind)
		{
			i--;
			ft_sa(list_a, data);
		}
		i--;
	}
}

void	ft_hundred_bis(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	j;
	int	loc1;
	int	loc2;

	i = 1;
	j = 1;
	loc1 = 0;
	loc2 = 0;
	while (loc1 != -1 || loc2 != -1)
	{
		loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		if (loc1 == -1 && i < ((data->size / data->thres) / 2) + 1)
			loc1 = ft_find_b_loc_1(*list_a, data, 1, ++i);
		loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		if (loc2 == -1 && j < ((data->size / data->thres) / 2) + 1)
			loc2 = ft_find_b_loc_2(*list_a, data, -1, ++j);
		if (find_b_gap2(*list_a, loc1, loc2) == loc1)
			ft_push_loc(list_a, loc1, list_b, data);
		else if (find_b_gap2(*list_a, loc1, loc2) == loc2)
		{
			ft_push_loc(list_a, loc2, list_b, data);
			ft_rb(list_b, data);
		}
	}
}

void	ft_hundred_hid_bis(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	j;
	int	loc1;
	int	loc2;

	i = 1;
	j = 1;
	loc1 = 0;
	loc2 = 0;
	while (loc1 != -1 || loc2 != -1)
	{
		loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		if (loc1 == -1 && i < ((data->size / data->thres) / 2) + 1)
			loc1 = ft_find_b_loc_1(*list_a, data, 1, ++i);
		loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		if (loc2 == -1 && j < ((data->size / data->thres) / 2) + 1)
			loc2 = ft_find_b_loc_2(*list_a, data, -1, ++j);
		if (find_b_gap2(*list_a, loc1, loc2) == loc1)
			ft_push_loc(list_a, loc1, list_b, data);
		else if (find_b_gap2(*list_a, loc1, loc2) == loc2)
		{
			ft_push_loc(list_a, loc2, list_b, data);
			ft_rb(list_b, data);
		}
	}
}
