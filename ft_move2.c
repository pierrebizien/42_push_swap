/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:37:05 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/30 15:54:35 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra(t_elem **list_a, int rr)
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
	if (rr == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_elem **list_b, int rr)
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
	if (rr == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_elem **list_a, t_elem **list_b)
{
	ft_ra(list_a, 1);
	ft_rb(list_b, 1);
	ft_printf("rr\n");
}

void	ft_rra(t_elem **list_a, int rrr)
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
	if (rrr == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_elem **list_b, int rrr)
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
	if (rrr == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_elem **list_a, t_elem **list_b)
{
	ft_rra(list_a, 1);
	ft_rra(list_b, 1);
	ft_printf("rrr\n");
}