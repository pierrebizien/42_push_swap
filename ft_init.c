/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:13 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 16:52:57 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_median(t_elem *list_a, int ac)
{
	t_elem *tmp;
	int		val;
	int		step;
	int		count;
	
	count = 0;
	tmp = list_a;
	step = INT_MIN;
	while (count < ac / 2)
	{
		val = INT_MAX;
		while (list_a)
		{
			if (list_a->val < val && step < list_a->val)
				val = list_a->val;
			list_a = list_a->next;
		}
		count++;
		list_a = tmp;
		step = val;
	}
	if (ac % 2 == 1)
		return (val + 1);
	else
		return (val);
}

int	ft_quart(t_elem *list_a, int ac)
{
	t_elem *tmp;
	int		val;
	int		step;
	int		count;
	
	count = 0;
	// index = 0;
	tmp = list_a;
	step = INT_MIN;
	val = list_a->val;
	while (count < ac / 4)
	{
		val = INT_MAX;
		while (list_a)
		{
			if (list_a->val < val && step < list_a->val)
			{
				val = list_a->val;
			}
			list_a = list_a->next;
		}
		count++;
		list_a = tmp;
		step = val;
	}
	// fprintf(stderr, "val vaut %d\n", val);
	return (val);
}

void	ft_set_index(t_elem **list_a, int index, int loc)
{
	int	i;
	t_elem *tmp;

	i = 0;
	tmp = *list_a;
	while (i < loc)
	{
		(*list_a) = (*list_a)->next;
		i++;
	}
	(*list_a)->ind = index;
	(*list_a) = tmp;
}

void	ft_init_index(t_elem **list_a)
{
	t_elem *tmp;
	
	tmp = *list_a;
	while (*list_a)
	{
		(*list_a)->ind = -1;
		*list_a = (*list_a)->next; 
	}
	*list_a = tmp;
}

void	ft_gen_index(t_elem **list_a, t_data *data)
{
	long	val;
	int i;
	int	loc;
	int index;
	t_elem	*tmp;
	
	index = 0;
	ft_init_index(list_a);
	tmp = *list_a;
	while (index < data->ac - 1)
	{
		val  = (long)INT_MAX + 1;
		i = 0;
		while (*list_a)
		{
			if ((*list_a)->val < val && (*list_a)->ind < 0)
			{
				val = (*list_a)->val;
				loc = i;
			}
			i++;
			(*list_a) = (*list_a)->next;
		}
		*list_a = tmp;
		ft_set_index(list_a, index, loc);
		index++;
	}
}