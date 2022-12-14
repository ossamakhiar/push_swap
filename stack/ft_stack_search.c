/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:39:43 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:40:34 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_min(t_stack *stack)
{
	int	min;

	min = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	ft_get_index(t_stack *stack, int key)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->data == key)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}
