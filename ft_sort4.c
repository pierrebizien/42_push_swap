/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:36:30 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_loc(t_elem **list_a, int loc, t_elem **list_b, t_data *data)
{
	int	size;

	size = ft_lst_size(*list_a);
	if (loc >= size / 2)
		ft_loop_rra(list_a, size - loc + 1, data);
	else
		ft_loop_ra(list_a, loc - 1, data);
	ft_pb(list_a, list_b, data);
}

void	ft_four2(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_rra(list_a, data);
	ft_pb(list_a, list_b, data);
	ft_three(list_a, data);
	ft_pa(list_a, list_b, data);
	if ((*list_a)->val > (*list_a)->next->val)
		ft_sa(list_a, data);
}

void	ft_hundred(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_hundred_bis(list_a, list_b, data);
	ft_send_home(list_a, list_b, data);
}

void	ft_hundred_hid(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_hundred_hid_bis(list_a, list_b, data);
	ft_send_home(list_a, list_b, data);
}
