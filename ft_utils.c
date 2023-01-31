/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:43:58 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_choose_index(int size, int index1, int index2)
{
	int	gap1;
	int	gap2;

	if (index1 > size - index1 - 1)
		gap1 = size - index1 -1;
	else
		gap1 = index1;
	if (index2 > size - index2 - 1)
		gap2 = size - index2 -1;
	else
		gap2 = index2;
	if (gap1 - gap2 > 1)
		return (index2);
	return (index1);
}
