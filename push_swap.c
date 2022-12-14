/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:52:38 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 16:02:50 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = NULL;
	top_b = NULL;
	if (ac < 2)
		_ft_putstr_fd("Invalid arguments !!\n", 2);
	if (stack_fill(ac, av, &top_a) == 0)
		_ft_putstr_fd("Error!!\n", 2);
	if (ac - 1 <= 40)
		sort_small_stack(&top_a, &top_b, ac - 1);
	else
		ft_large_sort(&top_a, &top_b);
	return (0);
}
