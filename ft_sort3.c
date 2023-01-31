/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:56:30 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:38:42 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
	{
		x = -x;
	}
	return (x);
}

int	ft_find_loc(t_elem *list_a, int index)
{
	int			i;
	int			loc1;
	int			loc2;
	static int	p_index = 0;

	if (p_index == 1)
		return (p_index = 0, ft_find_loc(list_a, index - 1));
	i = 0;
	while (list_a)
	{
		if (list_a->ind == index)
			loc1 = i;
		if (list_a->ind == index + 1)
			loc2 = i;
		i++;
		list_a = list_a->next;
	}
	if (ft_abs(loc1 - (ft_lst_size(list_a) / 2)) > \
		loc2 - (ft_lst_size(list_a) / 2) + 1)
	{
		p_index = 1;
		return (loc2);
	}
	return (loc1);
}

int	ft_b_gap(t_elem *list_a, int j, t_data *data)
{
	(void)list_a;
	if (ft_abs(j) < ft_abs(data->size - j))
	{
		return (j);
	}
	else
	{
		return (ft_abs(data->size - j));
	}
}

int	find_b_gap2(t_elem *list_a, int a, int b)
{
	int	size;
	int	tmpa;
	int	tmpb;		

	if (a == -1 && b == -1)
		return (0);
	if (a == -1)
		return (b);
	if (b == -1)
		return (a);
	size = ft_lst_size(list_a);
	if (a <= ft_abs(size - a) + 1)
		tmpa = a;
	else
		tmpa = ft_abs(size - a);
	if (b <= ft_abs(size - b) + 1)
		tmpb = b;
	else
		tmpb = ft_abs(size - b) + 1;
	if (tmpa > tmpb)
		return (b);
	else
		return (a);
}

int	ft_find_b_loc_1(t_elem *list_a, t_data *data, int sens, int i)
{
	int	j;
	int	loc;
	int	gap;

	j = 0;
	(void)sens;
	loc = -1;
	gap = INT_MAX;
	while (list_a)
	{
		if (list_a->ind > data->size / 2 && list_a->ind <= \
			((data->size / 2) + (data->thres * i)))
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
