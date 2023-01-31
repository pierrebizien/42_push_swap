/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:46:34 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:10:09 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_two(t_elem **list_a, t_data *data)
{
	if ((*list_a)->val < (*list_a)->next->val)
		return ;
	else
		ft_ra(list_a, data);
	return ;
}

int	ft_is_sorted(t_elem *list)
{
	t_elem	*tmp;

	tmp = list;
	list = list->next;
	while (list)
	{
		if (tmp->val < list->val)
		{
			tmp = list;
			list = list->next;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_three(t_elem **list_a, t_data *data)
{
	if (ft_is_sorted(*list_a))
		return ;
	while (!ft_is_sorted(*list_a))
	{
		if ((*list_a)->val > (*list_a)->next->val && \
			(*list_a)->val > (*list_a)->next->next->val)
			ft_ra(list_a, data);
		if ((*list_a)->val > (*list_a)->next->val)
			ft_sa(list_a, data);
		if ((*list_a)->next->val > (*list_a)->next->next->val)
			ft_rra(list_a, data);
		else if (!ft_is_sorted(*list_a))
		{
			ft_rra(list_a, data);
			ft_sa(list_a, data);
		}
	}
}

void	ft_four(t_elem **list_a, t_elem **list_b, t_data *data)
{
	if (ft_is_sorted((*list_a)->next))
		ft_ra(list_a, data);
	if ((*list_a)->val <= data->median)
	{
		ft_pb(list_a, list_b, data);
		ft_three(list_a, data);
		ft_pa(list_a, list_b, data);
		if ((*list_a)->val > (*list_a)->next->val)
			ft_sa(list_a, data);
	}
	else if ((*list_a)->next->val <= data->median)
	{
		ft_ra(list_a, data);
		ft_pb(list_a, list_b, data);
		ft_three(list_a, data);
		ft_pa(list_a, list_b, data);
		if ((*list_a)->val > (*list_a)->next->val)
			ft_sa(list_a, data);
	}
	else
	{
		ft_four2(list_a, list_b, data);
	}
}

void	ft_five(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int		i;

	i = 0;
	data->median = ft_median(*list_a, 5);
	if (ft_is_sorted(*list_a))
		return ;
	while (i < data->size)
	{
		if ((*list_a)->val < data->median)
		{
			ft_pb(list_a, list_b, data);
		}
		else
			ft_ra(list_a, data);
		i++;
	}
	ft_three(list_a, data);
	if ((*list_b)->val < (*list_b)->next->val)
		ft_sb(list_b, data);
	ft_pa(list_a, list_b, data);
	ft_pa(list_a, list_b, data);
}
