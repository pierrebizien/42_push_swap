/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:07:52 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 17:24:45 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_choose_index(int size, int index1, int index2)
{
	int gap1;
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

// int ft_find_best_min(t_elem *list_a)
// {
//     int index1;
//     int index2;
//     int tmp1;
//     t_elem *tmp2;
// 	int	i;
	
//     index1 = 0;
//     index2 = 0;
// 	tmp2 = list_a;
// 	tmp1 = list_a->val;
// 	i = 0;
//     while (list_a)
//     {
//         if (list_a-> < tmp1)
//         {
// 			tmp1 = list_a->val;
// 			index2 = index1;
// 			index1 = i;
//         }
//         list_a = list_a->next;
// 		i++;
//     }
// 	list_a = tmp2;
// 	return (ft_choose_index(ft_lst_size(list_a), index1, index2));
// }