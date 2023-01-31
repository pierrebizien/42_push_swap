/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:48:49 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:49:37 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sa(t_elem **list_a, t_data *data)
{
	t_elem	*begin;
	int		tmp;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	begin = *list_a;
	tmp = begin->val;
	begin->val = begin->next->val;
	begin->next->val = tmp;
	if (data->hid == 0)
		ft_printf("sa\n");
	else
		data->info_b.count++;
}

void	ft_sb(t_elem **list_b, t_data *data)
{
	t_elem	*begin;
	int		tmp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	begin = *list_b;
	tmp = begin->val;
	begin->val = begin->next->val;
	begin->next->val = tmp;
	if (data->hid == 0)
		ft_printf("sb\n");
	else
		data->info_b.count++;
}

void	ft_ss(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_sa(list_a, data);
	ft_sb(list_b, data);
	if (data->hid == 0)
		ft_printf("ss\n");
	else
		data->info_b.count++;
}

void	ft_pb(t_elem **list_a, t_elem **list_b, t_data *data)
{
	t_elem	*tmp_a;

	if (!list_a)
		return ;
	tmp_a = (*list_a)->next;
	if (list_b)
		(*list_a)->next = *list_b;
	else
		(*list_a)->next = NULL;
	*list_b = *list_a;
	*list_a = tmp_a;
	if (data->hid == 0)
		ft_printf("pb\n");
	else
		data->info_b.count++;
}

void	ft_pa(t_elem **list_a, t_elem **list_b, t_data *data)
{
	t_elem	*tmp_a;

	if (!(*list_b))
		return ;
	tmp_a = (*list_b)->next;
	if (list_a)
		(*list_b)->next = *list_a;
	else
		(*list_b)->next = NULL;
	*list_a = *list_b;
	*list_b = tmp_a;
	if (data->hid == 0)
		ft_printf("pa\n");
	else
		data->info_b.count++;
}
