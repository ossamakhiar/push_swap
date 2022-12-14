/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_traverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:37:05 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:57:55 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	dub_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->data == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_fill(int ac, char **av, t_stack **top)
{
	int	i;
	int	value;

	i = ac - 1;
	while (i >= 1)
	{
		if (!ft_is_digits(av[i]))
			return (0);
		value = ft_atoi(av[i]);
		if (dub_value(*top, value))
			return (0);
		stack_push(top, ft_stacknew(value));
		i--;
	}
	return (1);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
