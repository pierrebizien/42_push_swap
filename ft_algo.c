/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:59 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 18:48:46 by pbizien          ###   ########.fr       */
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