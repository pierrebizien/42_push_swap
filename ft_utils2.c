/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:04:18 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:43:17 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_len_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int	ft_check_same(t_elem *list)
{
	t_elem	*tmp;

	tmp = list;
	while (tmp)
	{
		list = tmp->next;
		while (list)
		{
			if (list->val == tmp->val)
				return (0);
			list = list->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_free(t_elem *begin)
{
	t_elem	*tmp;

	tmp = begin;
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

t_elem	*ft_generate_a_l(char **av, int ac, t_data *data)
{
	t_elem	*begin;
	t_elem	*tmp_l;
	int		i;

	if (ft_atoi(av[1]) == 3147483648)
		return (NULL);
	begin = ft_lst_new(ft_atoi(av[1]), 1);
	tmp_l = begin;
	i = 2;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == 3147483648)
			return (ft_free(tmp_l), NULL);
		begin->next = ft_lst_new(ft_atoi(av[i]), i);
		begin = begin->next;
		i++;
	}
	if (!ft_check_same(tmp_l))
	{
		ft_free(tmp_l);
		return (NULL);
	}
	begin = NULL;
	data->size = i;
	return (tmp_l);
}

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
