/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:45:48 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 13:52:18 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_elem	*ft_lst_new(int content, int index)
{
	t_elem	*ptr;

	ptr = ft_calloc(1, sizeof(t_elem));
	if (!ptr)
		return (NULL);
	ptr->val = content;
    ptr->ind = index;
	return (ptr);
}

t_elem  *ft_lst_new_empty(void)
{
    t_elem	*ptr;

	ptr = ft_calloc(1, sizeof(t_elem));
	if (!ptr)
		return (NULL);
    ptr->ind = 0;
	return (ptr);
}