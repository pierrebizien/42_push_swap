/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbizien <pbizien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:43 by pbizien           #+#    #+#             */
/*   Updated: 2022/11/08 10:02:04 by pbizien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi() function converts the initial portion of the string
//        pointed to by nptr to int

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((nptr[i] <= '9') && (nptr[i] >= '0') && nptr[i])
	{
		count = count * 10 + (nptr[i] - '0');
		i++;
	}
	return (count * sign);
}

/*

int	main(int ac, char**av)
{
	(void)ac;
	(void)av;
	printf("réelle %d  \n", atoi("\t 4 2"));
	printf("moi %d  \n", ft_atoi("\t 4 2"));

}
*/