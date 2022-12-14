/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:13:26 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/12 22:50:39 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index_(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->data >= min && stack->data <= max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	max_to_top_b(t_stack **top_b)
{
	int	i;
	int	size;
	int	i_max;

	i = 0;
	size = ft_stack_size(*top_b);
	i_max = ft_get_index(*top_b, ft_get_max(*top_b));
	if (i_max <= size / 2)
		while (i++ < i_max)
			(rotate_ab(top_b), ft_putstr("rb\n"));
	else if (i_max > size / 2)
		while (i++ < size - i_max)
			(rev_rotate_ab(top_b), ft_putstr("rrb\n"));
}

int	is_down_full(t_stack *stack)
{
	if (!is_sorted(stack))
		return (1);
	return (0);
}

int	ft_bottom_data(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (0);
	last = ft_stacklast(stack);
	return (last->data);
}

int	check_max_on_b(t_stack *stack, int max)
{
	while (stack)
	{
		if (stack->data == max)
			return (1);
		stack = stack->next;
	}
	return (0);
}
