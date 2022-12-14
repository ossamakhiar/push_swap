/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:06:11 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/13 23:16:45 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	long	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		tmp *= 10;
		tmp += str[i] - 48;
		if (tmp > __INT_MAX && sign > 0)
			_ft_putstr_fd("ERORR\n", 2);
		else if (tmp > __INT_MIN)
			_ft_putstr_fd("ERORR\n", 2);
		result = tmp;
		i++;
	}
	return (result * sign);
}
