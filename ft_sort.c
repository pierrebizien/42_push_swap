/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 17:07:32 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	ft_sep_med(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (i < data->size && count < (data->size / 2))
	{
		if ((*list_a)->val < data->median)
		{
			ft_pb(list_a, list_b);
			count++;
		}
		else
			ft_ra(list_a, 0);
		i++;
	}
}
void	ft_two(t_elem **list_a)
{
	if ((*list_a)->val < (*list_a)->next->val)
		return ;
	else 
		ft_ra(list_a, 0);
	return ;
}

int	ft_is_sorted(t_elem *list)
{
	t_elem *tmp;

	tmp  = list;
	list = list->next;
	while (list)
	{
		if (tmp->val < list->val)
		{
			tmp = list;
			list = list->next;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_is_sorted_r(t_elem *list)
{
	t_elem *tmp;

	tmp  = list;
	list = list->next;
	while (list)
	{
		if (tmp->val > list->val)
		{
			tmp = list;
			list = list->next;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_three(t_elem **list_a)
{
	if (ft_is_sorted(*list_a))
		return ;
	while (!ft_is_sorted(*list_a))
	{
		// if ((*list_a)->val > (*list_a)->next->val && (*list_a)->next->val < (*list_a)->next->next->val)
		// 	ft_ra(list_a, 0);
		if((*list_a)->val > (*list_a)->next->val && (*list_a)->val > (*list_a)->next->next->val)
			ft_ra(list_a, 0);
		if((*list_a)->val > (*list_a)->next->val)
			ft_sa(list_a, 0);
		if((*list_a)->next->val > (*list_a)->next->next->val)
			ft_rra(list_a, 0);
		else if (!ft_is_sorted(*list_a))
		{
			ft_rra(list_a, 0);
			ft_sa(list_a, 0);
		}
	}
}

void	ft_three_r(t_elem **list_b)
{
	if (ft_is_sorted_r(*list_b))
		return ;
	while (!ft_is_sorted_r(*list_b))
	{
		if((*list_b)->val < (*list_b)->next->val && (*list_b)->val < (*list_b)->next->next->val)
			ft_rb(list_b, 0);
		if((*list_b)->val < (*list_b)->next->val)
			ft_sb(list_b, 0);
		if((*list_b)->next->val < (*list_b)->next->next->val)
			ft_rrb(list_b, 0);
		else if (!ft_is_sorted_r(*list_b))
		{
			ft_rrb(list_b, 0);
			ft_sb(list_b, 0);
		}
	}
}


void	ft_four(t_elem **list_a, t_elem **list_b, t_data *data)
{
		if (ft_is_sorted((*list_a)->next))
			ft_ra(list_a, 0);
		if ((*list_a)->val <= data->median)
		{
			ft_pb(list_a, list_b);
			ft_three(list_a);
			ft_pa(list_a, list_b);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, 0);
		}
		else if ((*list_a)->next->val <= data->median)
		{
			ft_ra(list_a, 0);
			ft_pb(list_a, list_b);
			ft_three(list_a);
			ft_pa(list_a, list_b);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, 0);
		}
		else 
		{
			ft_rra(list_a, 0);
			ft_pb(list_a, list_b);
			ft_three(list_a);
			ft_pa(list_a, list_b);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, 0);
		}
}

void	ft_five(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int		i;

	i = 0;
	data->median = ft_median(*list_a, 5);
	if(ft_is_sorted(*list_a))
		return ;
	while (i < data->size)
	{
		if ((*list_a)->val < data->median)
		{
			ft_pb(list_a, list_b);
		}
		else
			ft_ra(list_a, 0);
		i++;
	}
	ft_three(list_a);
	if ((*list_b)->val < (*list_b)->next->val)
		ft_sb(list_b, 0);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
}


void	ft_five_b(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int		i;

	i = 0;
	if(ft_is_sorted(*list_b))
		return ;
	while (i < data->size)
	{
		if ((*list_b)->val > data->median)
		{
			ft_pa(list_a, list_b);
		}
		else
			ft_rb(list_b, 0);
		i++;
	}
	// fprintf(stderr, "IS SORTED R ? %d \n", ft_is_sorted_r(*list_b));
	ft_three_r(list_b);
	if ((*list_a)->val > (*list_a)->next->val)
		ft_sa(list_a, 0);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
	ft_pa(list_a, list_b);
}

void	ft_ten(t_elem **list_a, t_elem **list_b, t_data *data)
{
	fprintf(stderr, "hey");
	if(ft_is_sorted(*list_a))
		return ;
	ft_sep_med(list_a, list_b, data);
	data->size = data->ac / 2;
	data->median = ft_median(*list_a, data->size);
	// fprintf(stderr, "median vaut %d\n", data->median);
	ft_five(list_a, list_b, data);
	data->median = ft_median(*list_b, data->size);
	// fprintf(stderr, "median vaut %d\n", data->median);
	ft_five_b(list_a, list_b, data);
	// ft_pb()
}
void	ft_loop_ra(t_elem **list_a, int nb)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_ra(list_a, 0);
		i++;
	}
}

void	ft_loop_rra(t_elem **list_a, int nb)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_rra(list_a, 0);
		i++;
	}
}

void	ft_loop_pa(t_elem **list_a, t_elem **list_b, int nb)
{
	int	i;
	
	i = 0;
	while (i < nb)
	{
		ft_pa(list_a, list_b);
		i++;
	}
}
int	ft_abs(int x)
{
	if (x < 0)
	{
		x = -x;
	}
	return (x);
}
void	ft_5_to_19(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int index;
	int count_2;

	count_2 = 0;
	index = 0;
	while (ft_lst_size(*list_a) > 5)
	{
		index = ft_find_best_min(*list_a);
		fprintf(stderr, "INDEX %d \n", index);
		if (index <= ft_lst_size(*list_a) / 2)
		{
			ft_loop_ra(list_a, index);
		}
		else
		{
			ft_loop_rra(list_a, ft_lst_size(*list_a) - index);
		}
		ft_print_a_b(*list_a, *list_b);
		ft_pb(list_a, list_b);
		count_2++;
		if (count_2 == 2)
		{
			if ((*list_b)->val < (*list_b)->next->val && ft_abs((*list_b)->ind - (*list_b)->next->ind) == 1)
				ft_sb(list_b, 0);
			count_2 = 0;
		}
		index++;
	}
	ft_five(list_a, list_b, data);
	ft_loop_pa(list_a, list_b, ft_lst_size(*list_b));
}
