/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:55 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/26 18:44:06 by pbizien          ###   ########.fr       */
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
	// fprintf(stderr, "hey");
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
	// int count_2;
	int	index;

	// count_2 = 0;
	loc = 0;
	index = 0;
	while (ft_lst_size(*list_a) > 3)
	{
		loc = ft_find_loc(*list_a, index);
		// fprintf(stderr, "LOC VAUT %d et COUNT VAUT %d et INDEX VAUT %d \n", loc, 5, index);
		if (loc <= ft_lst_size(*list_a) / 2)
		{
			ft_loop_ra(list_a, loc);
		}
		else
			ft_loop_rra(list_a, ft_lst_size(*list_a) - loc);
		ft_pb(list_a, list_b);
		// ft_print_a_b(*list_a, *list_b);
		// count_2++;
		if (ft_lst_size(*list_b) > 1)
		{
			if ((*list_b)->val < (*list_b)->next->val && ft_abs((*list_b)->ind - (*list_b)->next->ind) == 1)
				ft_sb(list_b, 0);
			// count_2 = 0;
		}
		index++;
	}
	ft_three(list_a);
	(void)data;
	ft_loop_pa(list_a, list_b, ft_lst_size(*list_b));
	// fprintf(stderr, "HEEEY");
}

void	ft_hundred(t_elem **list_a, t_elem **list_b, t_data *data)
{
	int	i;

	i = 1;
	while (data->thres * i < (data->ac - 1))
	{
		if ((*list_a)->ind < data->thres * i)
			//PARTIR DE LA MEDIANE ET REGARDER GROUPE DU DESSUS ET DU DESSOUS UNE FOIS QUE REMPLI ON PASSE AU GROUPE D'APRES		
	

		i++;
	}
	
}
