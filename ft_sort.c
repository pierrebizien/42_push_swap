/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 15:48:48 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


// void	ft_sep_med(t_elem **list_a, t_elem **list_b, t_data *data)
// {
// 	int i;
// 	int count;
	
// 	i = 0;
// 	count = 0;
// 	while (i < data->size && count < (data->size / 2))
// 	{
// 		if ((*list_a)->val < data->median)
// 		{
// 			ft_pb(list_a, list_b, );
// 			count++;
// 		}
// 		else
// 			ft_ra(list_a, 0);
// 		i++;
// 	}
// }
void	ft_two(t_elem **list_a, t_data *data)
{
	if ((*list_a)->val < (*list_a)->next->val)
		return ;
	else 
		ft_ra(list_a, data);
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

void	ft_three(t_elem **list_a, t_data *data)
{
	if (ft_is_sorted(*list_a))
		return ;
	while (!ft_is_sorted(*list_a))
	{
		// if ((*list_a)->val > (*list_a)->next->val && (*list_a)->next->val < (*list_a)->next->next->val)
		// 	ft_ra(list_a, 0);
		if((*list_a)->val > (*list_a)->next->val && (*list_a)->val > (*list_a)->next->next->val)
			ft_ra(list_a, data);
		if((*list_a)->val > (*list_a)->next->val)
			ft_sa(list_a, data);
		if((*list_a)->next->val > (*list_a)->next->next->val)
			ft_rra(list_a, data);
		else if (!ft_is_sorted(*list_a))
		{
			ft_rra(list_a, data);
			ft_sa(list_a, data);
		}
	}
}

void	ft_three_r(t_elem **list_b, t_data *data)
{
	if (ft_is_sorted_r(*list_b))
		return ;
	while (!ft_is_sorted_r(*list_b))
	{
		if((*list_b)->val < (*list_b)->next->val && (*list_b)->val < (*list_b)->next->next->val)
			ft_rb(list_b, data);
		if((*list_b)->val < (*list_b)->next->val)
			ft_sb(list_b, data);
		if((*list_b)->next->val < (*list_b)->next->next->val)
			ft_rrb(list_b, data);
		else if (!ft_is_sorted_r(*list_b))
		{
			ft_rrb(list_b, data);
			ft_sb(list_b, data);
		}
	}
}


void	ft_four(t_elem **list_a, t_elem **list_b, t_data *data)
{
		if (ft_is_sorted((*list_a)->next))
			ft_ra(list_a, data);
		if ((*list_a)->val <= data->median)
		{
			ft_pb(list_a, list_b, data);
			ft_three(list_a, data);
			ft_pa(list_a, list_b, data);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, data);
		}
		else if ((*list_a)->next->val <= data->median)
		{
			ft_ra(list_a, data);
			ft_pb(list_a, list_b, data);
			ft_three(list_a, data);
			ft_pa(list_a, list_b, data);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, data);
		}
		else 
		{
			ft_rra(list_a, data);
			ft_pb(list_a, list_b, data);
			ft_three(list_a, data);
			ft_pa(list_a, list_b, data);
			if ((*list_a)->val > (*list_a)->next->val)
				ft_sa(list_a, data);
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
			ft_pb(list_a, list_b, data);
		}
		else
			ft_ra(list_a, data);
		i++;
	}
	ft_three(list_a, data);
	if ((*list_b)->val < (*list_b)->next->val)
		ft_sb(list_b, data);
	ft_pa(list_a, list_b, data);
	ft_pa(list_a, list_b, data);
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
			ft_pa(list_a, list_b, 0);
		}
		else
			ft_rb(list_b, 0);
		i++;
	}
	// fprintf(stderr, "IS SORTED R ? %d \n", ft_is_sorted_r(*list_b));
	ft_three_r(list_b, data);
	if ((*list_a)->val > (*list_a)->next->val)
		ft_sa(list_a, 0);
	ft_pa(list_a, list_b, 0);
	ft_pa(list_a, list_b, 0);
	ft_pa(list_a, list_b, 0);
}

// void	ft_ten(t_elem **list_a, t_elem **list_b, t_data *data)
// {
// 	// fprintf(stderr, "hey");
// 	if(ft_is_sorted(*list_a))
// 		return ;
// 	ft_sep_med(list_a, list_b, data);
// 	data->size = data->ac / 2;
// 	data->median = ft_median(*list_a, data->size);
// 	// fprintf(stderr, "median vaut %d\n", data->median);
// 	ft_five(list_a, list_b, data);
// 	data->median = ft_median(*list_b, data->size);
// 	// fprintf(stderr, "median vaut %d\n", data->median);
// 	ft_five_b(list_a, list_b, data);
// 	// ft_pb()
// }
void	ft_loop_ra(t_elem **list_a, int nb, t_data *data)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_ra(list_a, data);
		i++;
	}
}

void	ft_loop_rb(t_elem **list_a, int nb, t_data *data)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_rb(list_a, data);
		i++;
	}
}

void	ft_loop_rra(t_elem **list_a, int nb, t_data *data)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_rra(list_a, data);
		i++;
	}
}

void	ft_loop_rrb(t_elem **list_a, int nb, t_data *data)
{
	int i;
	
	i = 0;
	while (i < nb)
	{
		ft_rra(list_a, data);
		i++;
	}
}

void	ft_loop_pa(t_elem **list_a, t_elem **list_b, int nb, t_data *data)
{
	int	i;
	
	i = 0;
	while (i < nb)
	{
		ft_pa(list_a, list_b, data);
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

int		ft_find_loc(t_elem *list_a, int index)
{
	int	i;
	int loc1;
	int loc2;
	static int p_index = 0;
	
	if (p_index == 1)
		return (p_index = 0, ft_find_loc(list_a, index - 1));
	i = 0;
	while (list_a)
	{
		if (list_a->ind == index)
			loc1 = i;
		if (list_a->ind == index + 1)
			loc2 = i;
		i++;
		list_a = list_a->next;
	}
	if (ft_abs(loc1 - (ft_lst_size(list_a) / 2)) >  loc2 - (ft_lst_size(list_a) / 2) + 1)
	{
		p_index = 1;
		return (loc2);
	}
	return (loc1);
}

void	ft_5_to_19(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int loc;
	int	index;

	loc = 0;
	index = 0;
	while (ft_lst_size(*list_a) > 3)
	{
		loc = ft_find_loc(*list_a, index);
		if (loc <= ft_lst_size(*list_a) / 2)
		{
			ft_loop_ra(list_a, loc, 0);
		}
		else
			ft_loop_rra(list_a, ft_lst_size(*list_a) - loc, NULL);
		ft_pb(list_a, list_b, NULL);
		if (ft_lst_size(*list_b) > 1)
		{
			if ((*list_b)->val < (*list_b)->next->val && ft_abs((*list_b)->ind - (*list_b)->next->ind) == 1)
				ft_sb(list_b, NULL);
		}
		index++;
	}
	ft_three(list_a, data);
	ft_loop_pa(list_a, list_b, ft_lst_size(*list_b), 0);
}

int	ft_b_gap(t_elem *list_a, int j, t_data *data)
{
	(void)list_a;
	
	if (ft_abs(j) < ft_abs(data->size - j))
	{
		return (j);
	}
	else
	{
		return (ft_abs(data->size - j));
	}
}

int find_b_gap2(t_elem *list_a, int a, int b)
{
	int	size;
	int tmpa;
	int	tmpb;		
	
	if (a == -1 && b == -1)
		return (0);
	if (a == -1)
		return (b);
	if (b == -1)
		return (a);
	size = ft_lst_size(list_a);
	if (a <= ft_abs(size - a) + 1)
		tmpa = a;
	else 
		tmpa = ft_abs(size - a);
	if (b <= ft_abs(size - b) + 1)
		tmpb = b;
	else
		tmpb = ft_abs(size - b) + 1;
	// fprintf(stderr, "size vaut %d a vaut %d, b vaut %d, temp a vaut %d et temp b vaut %d\n",size, a, b, tmpa, tmpb);
	if (tmpa > tmpb)
		return (b);
	else
		return (a);
		
	
}

int	ft_find_b_loc_1(t_elem *list_a, t_data *data, int sens, int i)
{
	int	j;
	int loc;
	int gap;

	j = 0;
	loc = -1;
	(void)sens;
	(void)data;
	(void)i;
	gap = INT_MAX;
	
	while (list_a)
	{
		if (list_a->ind > data->size / 2 && list_a->ind <= ((data->size / 2) + (data->thres * i)))
		{
			if (ft_b_gap(list_a, j, data) < gap)
			{
				gap = ft_b_gap(list_a, j, data);
				loc = j + 1;
			}
		}
		list_a = list_a->next;
		j++;
	}
	return (loc);
}

int	ft_find_b_loc_2(t_elem *list_a, t_data *data, int sens, int i)
{
	int	j;
	int loc;
	int gap;

	j = 0;
	loc = -1;
	(void)sens;
	(void)data;
	(void)i;
	gap = INT_MAX;
	while (list_a)
	{
		if (list_a->ind <= data->size / 2 && list_a->ind > ((data->size / 2) - (data->thres * i)))
		{
			// fprintf(stderr, "LOC2 on rentre avec ind qui vaut %d j vaut %d\n", list_a->ind, j);
			if (ft_b_gap(list_a, j, data) < gap)
			{
				gap = ft_b_gap(list_a, j, data);
				loc = j + 1;
			}
		}
		list_a = list_a->next;
		j++;
	}
	// fprintf(stderr, "LOC VAUT %d\n", loc);
	return (loc);
}

void	ft_push_loc(t_elem **list_a, int loc, t_elem **list_b, t_data *data)
{
	int size;
	(void)list_b;
	(void)loc;
	(void)list_a;
	size  = ft_lst_size(*list_a);
	(void)size;
	// ft_print_a_b(*list_a, *list_b);

	if (loc >= size / 2)
		ft_loop_rra(list_a, size - loc + 1, data);
	else
		ft_loop_ra(list_a, loc - 1, data);
	ft_pb(list_a, list_b, data);
}

int	ft_find_loc_2(t_elem **list_b, int index)
{
	t_elem *tmp;
	int	i;

	i = 1;
	tmp = *list_b;
	while (tmp)
	{
		if (tmp->ind == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
	
}

void	ft_send_home(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	loc_h;
	
	i = data->size;
	while (i >= 1)
	{
		loc_h = ft_find_loc_2(list_b, i);
		while ((*list_b)->ind != i)
		{
			// fprintf(stderr, "ind vaut %d et i vaut %d\n", (*list_b)->ind, i);
			if ((*list_b)->ind == i - 1)
				ft_pa(list_a, list_b, data);
			else if (loc_h <= ft_lst_size(*list_b) / 2)
				ft_rb(list_b, data);
			else
				ft_rrb(list_b, data);
		}
		ft_pa(list_a, list_b, data);
		if ((*list_a)->next && (*list_a)->ind > (*list_a)->next->ind)
		{
			i--;
			ft_sa(list_a, data);
		}
		i--;
	}
}

void	ft_hundred(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	j;
	int	loc1;
	int	loc2;

	i = 1;
	j = 1;
	loc1 = 0;
	loc2 = 0;
	data->hid = 0;
	while (loc1 != -1 || loc2 != -1)
	{
		loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		if (loc1 == -1 && i < ((data->size / data->thres) / 2) + 1)
		{
			i++;
			loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		}
		loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		if (loc2 == -1 && j < ((data->size / data->thres) / 2) + 1)
		{
			j++;
			loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		}
		if (find_b_gap2(*list_a, loc1, loc2) == loc1)
			ft_push_loc(list_a, loc1, list_b, data);
		else if (find_b_gap2(*list_a, loc1, loc2) == loc2)
		{
			ft_push_loc(list_a, loc2, list_b, data);
			ft_rb(list_b, data);
		}
	}
	ft_send_home(list_a, list_b, data);
}

void	ft_hundred_hid(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;
	int	j;
	int	loc1;
	int	loc2;
	(void)list_b;

	i = 1;
	j = 1;
	loc1 = 0;
	loc2 = 0;
	data->hid = 1;
	while (loc1 != -1 || loc2 != -1)
	{
		
		loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		if (loc1 == -1 && i < ((data->size / data->thres) / 2) + 1)
		{
			i++;
			loc1 = ft_find_b_loc_1(*list_a, data, 1, i);
		}
		loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		if (loc2 == -1 && j < ((data->size / data->thres) / 2) + 1)
		{
			j++;
			loc2 = ft_find_b_loc_2(*list_a, data, -1, j);
		}
		if (find_b_gap2(*list_a, loc1, loc2) == loc1)
			ft_push_loc(list_a, loc1, list_b, data);
		else if (find_b_gap2(*list_a, loc1, loc2) == loc2)
		{
			ft_push_loc(list_a, loc2, list_b, data);
			ft_rb(list_b, data);
		}
	}
	ft_send_home(list_a, list_b, data);
}
