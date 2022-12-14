/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:37:48 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/13 22:40:35 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	execute_sa_ra_rra(t_stack **top_a, int action)
{
	(ft_putstr("sa\n"), swap_ab(top_a));
	if (action)
		(ft_putstr("ra\n"), rotate_ab(top_a));
	else
		(ft_putstr("rra\n"), rev_rotate_ab(top_a));
}

void	sort_three(t_stack **top_a)
{
	int		min;
	int		max;
	t_stack	*tmp;

	tmp = ft_stacklast(*top_a);
	min = ft_get_min(*top_a);
	max = ft_get_max(*top_a);
	if (!is_sorted(*top_a))
	{
		if ((*top_a)->data > (*top_a)->next->data && tmp->data == max)
			(ft_putstr("sa\n"), swap_ab(top_a));
		else if ((*top_a)->data < (*top_a)->next->data && tmp->data == min)
			(ft_putstr("rra\n"), rev_rotate_ab(top_a));
		else if ((*top_a)->data > (*top_a)->next->data && tmp->data == min)
			execute_sa_ra_rra(top_a, 0);
		else if ((*top_a)->data == min && tmp->data != max)
			execute_sa_ra_rra(top_a, 1);
		else if ((*top_a)->data == max && tmp->data != min)
			(ft_putstr("ra\n"), rotate_ab(top_a));
	}
}

void	simple_sort(t_stack **top_a, t_stack **top_b, int size)
{
	int	i_min;

	while (!is_sorted(*top_a))
	{
		i_min = ft_get_index(*top_a, ft_get_min(*top_a));
		if (i_min < 0)
			return ;
		if (i_min <= size / 2)
			while (i_min--)
				(ft_putstr("ra\n"), rotate_ab(top_a));
		else
			while (size - i_min > 0)
				(ft_putstr("rra\n"), rev_rotate_ab(top_a)), i_min++;
		if (!is_sorted(*top_a))
			(push_b(top_a, top_b), ft_putstr("pb\n"), size--);
		if (size == 3)
			sort_three(top_a);
	}
	while (!is_empty(*top_b))
		(push_a(top_a, top_b), ft_putstr("pa\n"));
}

void	sort_small_stack(t_stack **top_a, t_stack **top_b, int size)
{
	if (size == 2 && (*top_a)->data > (*top_a)->next->data)
	{
		ft_putstr("sa\n");
		swap_ab(top_a);
	}
	else if (size == 3)
		sort_three(top_a);
	else
		simple_sort(top_a, top_b, size);
}
