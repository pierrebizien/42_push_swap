/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:45:21 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 18:46:01 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rrr(t_elem **list_a, t_elem **list_b, t_data *data)
{
	ft_rra(list_a, data);
	ft_rra(list_b, data);
	if (data->hid == 0)
		ft_printf("rrr\n");
	else
		data->info_b.count++;
}
