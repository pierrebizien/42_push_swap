/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:59 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 17:51:45 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lst_size(t_elem *list_a)
{
	int	count;

	count = 0;
	while (list_a)
	{
		list_a = list_a->next;
		count++;
	}
	return (count);
}

void ft_separate(t_elem **list_a, t_elem **list_b, t_data *data)
{
	// t_elem *tmp;
	int	i;
	int	size;
	
	i = 0;
	size = ft_lst_size(*list_a);
	ft_print_a_b(*list_a, *list_b);
	while (i < size)
	{
		if ((*list_a)->val < data->median)
		{
			ft_pb(list_a, list_b);
		}
		else 
			ft_ra(list_a, 0);
		ft_print_a_b(*list_a, *list_b);
		// if(*list_a)
			// *list_a = (*list_a)->next;
		i++;
	}
}