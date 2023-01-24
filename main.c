/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:01:00 by pbizien           #+#    #+#             */
/*   Updated: 2023/01/24 11:26:58 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_free_double_c(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

int *ft_generate_a(char *av, t_data *data)
{
	char 	**tmp;
	int		i;
	int		count;
	int		*output;
	int		j;
	
	count = 0;
	tmp = ft_split(av, ' ');
	while (tmp[count])
		count++;
	data->size = count;
	output = ft_calloc(sizeof(int), count * 2);
	if (!output)
		return (NULL);
	i = count - 1;
	j = 0;
	while (i >= 0)
	{
		output[j] = ft_atoi(tmp[i]);
		i--;
		j++;
	}
	ft_free_double_c(tmp);
	return (output);
}

void	ft_print_tabs(int *tab_a, int *tab_b, t_data *data)
{
	int	i;

	i = data->size - 1;
	ft_printf("----------\n");
	while (i >= 0)
	{
		ft_printf("A %d | B %d\n", tab_a[i], tab_b[i]);
		ft_printf("----------\n");
		i--;
	}
}



int main(int ac, char **av)
{
    int		*tab_a;
	int		*tab_b;
	t_data	data;

	tab_a = ft_generate_a(av[1], &data);
	if (!tab_a)
		return (-1);
	tab_b = ft_calloc(sizeof(int), data.size);
	if (!tab_b)
		return (free(tab_a), -1);
    (void)ac;
	ft_print_tabs(tab_a, tab_b, &data);
}
