/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:01:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/31 19:54:38 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	ft_d_quotes(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_print_result(t_data *data, t_elem **begin_a, t_elem **begin_b, char **av)
{
	data->hid = 0;
	data->thres = data->info_b.bloc;
	*begin_a = ft_generate_a_l(av, data->ac, data);
	data->median = ft_median(*begin_a, data->ac);
	data->size = ft_lst_size(*begin_a);
	ft_gen_index(begin_a, data, 0);
	ft_hundred(begin_a, begin_b, data);
	ft_free(*begin_a);
	return (0);
}

void	ft_other_ac(t_data *data, t_elem **begin_a, t_elem **begin_b, char **av)
{
	int	i;

	i = 2;
	data->info_b.bcount = -1;
	ft_free(*begin_a);
	data->hid = 1;
	while (i < 50)
	{
		data->thres = i;
		*begin_a = ft_generate_a_l(av, data->ac, data);
		data->size = ft_lst_size(*begin_a);
		ft_gen_index(begin_a, data, 0);
		ft_hundred_hid(begin_a, begin_b, data);
		if (data->info_b.count < data->info_b.bcount || \
			data->info_b.bcount == -1)
		{
			data->info_b.bcount = data->info_b.count;
			data->info_b.bloc = i;
		}
		ft_free(*begin_a);
		data->info_b.count = 0;
		i++;
	}
}

int	ft_main_suite(t_data *data, t_elem **begin_a, t_elem **begin_b, char **av)
{
	if (data->ac == 3)
		return (ft_two(begin_a, data), ft_free(*begin_a), 0);
	if (data->ac == 4)
		return (ft_three(begin_a, data), ft_free(*begin_a), 0);
	if (data->ac == 5)
		return (ft_four(begin_a, begin_b, data), ft_free(*begin_a), 0);
	if (data->ac == 6)
		return (ft_five(begin_a, begin_b, data), ft_free(*begin_a), 0);
	ft_other_ac(data, begin_a, begin_b, av);
	return (ft_print_result(data, begin_a, begin_b, av));
}

int	main(int ac, char **av)
{
	t_data	data;
	t_elem	*begin_a;
	t_elem	*begin_b;

	if (ac == 1 && ft_d_quotes(av, ac))
		return (0);
	if ((ac == 2 && ft_atoi(av[1]) == 3147483648) || !ft_d_quotes(av, ac))
		return (write(2, "Error\n", 6), -1);
	if (ac == 2)
		return (0);
	begin_b = NULL;
	data.info_b.count = 0;
	data.hid = 0;
	data.ac = ac;
	begin_a = ft_generate_a_l(av, ac, &data);
	if (!begin_a)
		return (write(2, "Error\n", 6), -1);
	data.median = ft_median(begin_a, ac);
	data.size = ft_lst_size(begin_a);
	ft_gen_index(&begin_a, &data, 0);
	if (ft_is_sorted(begin_a))
		return (ft_free(begin_a), 0);
	return (ft_main_suite(&data, &begin_a, &begin_b, av));
}
