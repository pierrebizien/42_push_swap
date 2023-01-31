/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:28 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:22:38 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_loop_ra(t_elem **list_a, int nb, t_data *data)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_ra(list_a, data);
		i++;
	}
}

void	ft_loop_rb(t_elem **list_a, int nb, t_data *data)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_rb(list_a, data);
		i++;
	}
}

void	ft_loop_rra(t_elem **list_a, int nb, t_data *data)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_rra(list_a, data);
		i++;
	}
}

void	ft_loop_rrb(t_elem **list_a, int nb, t_data *data)
{
	int	i;

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
