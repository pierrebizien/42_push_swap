/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:37:05 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 14:11:06 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra(t_elem **list_a, t_data *data)
{
	t_elem	*last;
	t_elem	*tmp;
	
	last = *list_a;
	tmp = (*list_a)->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = (*list_a);
	(*list_a)->next = NULL;
	(*list_a) = tmp;
	if (data->hid == 0)
		ft_printf("ra\n");
	else
		data->info_b.count++;
}

void	ft_rb(t_elem **list_b, t_data *data)
{
	t_elem	*last;
	t_elem	*tmp;
	
	last = *list_b;
	tmp = (*list_b)->next;
	if (ft_lst_size(*list_b) <= 1)
		return ;
	while (last->next)
	{
		last = last->next;
	}
	last->next = (*list_b);
	(*list_b)->next = NULL;
	(*list_b) = tmp;
	if (data->hid == 0)
		ft_printf("rb\n");
	else
		data->info_b.count++;
}

void	ft_rr(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_ra(list_a, data);
	ft_rb(list_b, data);
	ft_printf("rr\n");
}

void	ft_rra(t_elem **list_a, t_data *data)
{
	t_elem	*last;
	t_elem *tmp;

	last = *list_a;
	if (ft_lst_size(*list_a) < 2)
		return ;
	while (last->next->next)
	{
		last = last->next;
	}
	tmp = last;
	last = last->next;
	last->next = *list_a;
	tmp-> next = NULL;
	*list_a = last;
	if (data->hid == 0)
		ft_printf("rra\n");
	else
		data->info_b.count++;
}

void	ft_rrb(t_elem **list_b, t_data *data)
{
	t_elem	*last;
	t_elem *tmp;

	last = *list_b;
	while (last->next->next)
	{
		last = last->next;
	}
	tmp = last;
	last = last->next;
	last->next = *list_b;
	tmp-> next = NULL;
	*list_b = last;
	if (data->hid == 0)
		ft_printf("rrb\n");
	else
		data->info_b.count++;
}

void	ft_rrr(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_rra(list_a, data);
	ft_rra(list_b, data);
	if (data->hid == 0)
		ft_printf("rrr\n");
	else
		data->info_b.count++;
		
	
}