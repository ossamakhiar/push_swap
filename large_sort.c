/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:24:43 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 16:01:27 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(t_stack *stack, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * size);
	while (stack)
	{
		tab[i] = stack->data;
		stack = stack->next;
		i++;
	}
	quick_sort(tab, 0, i - 1);
	return (tab);
}

void	update_chunk_ends(int *start, int *end, int offset, int size)
{
	if (*start - offset < 0)
		*start = 0;
	else
		*start -= offset;
	if (*end + offset > size - 1)
		*end = size - 1;
	else
		*end += offset;
}

void	push_chunks(t_stack **top_a, t_stack **top_b, int *sorted, t_ctls ctls)
{
	int	elem;
	int	size;
	int	i;

	size = ft_stack_size(*top_a);
	elem = ft_get_index_(*top_a, sorted[ctls.start], sorted[ctls.end]);
	while (elem >= 0)
	{
		i = 0;
		if (elem < size / 2)
			while (i++ < elem)
				(rotate_ab(top_a), ft_putstr("ra\n"));
		else if (elem >= size)
			while (i++ < size - elem)
				(rev_rotate_ab(top_a), ft_putstr("rra\n"));
		(push_b(top_a, top_b), ft_putstr("pb\n"));
		size--;
		if ((*top_b)->data < sorted[ctls.mid] && (*top_b)->next)
			(rotate_ab(top_b), ft_putstr("rb\n"));
		elem = ft_get_index_(*top_a, sorted[ctls.start], sorted[ctls.end]);
	}
}

void	push_back(t_stack **top_a, t_stack **top_b, int	*sorted_arr, int i)
{
	int	down;

	down = 0;
	while (!is_empty(*top_b))
	{
		down = is_down_full(*top_a);
		if (!check_max_on_b(*top_b, sorted_arr[i]))
			(rev_rotate_ab(top_a), ft_putstr("rra\n"), i--);
		else if ((*top_b)->data == sorted_arr[i])
			(push_a(top_a, top_b), ft_putstr("pa\n"), i--);
		else if (*top_a && (down == 0 \
			|| (*top_b)->data > ft_bottom_data(*top_a)))
		{
			(push_a(top_a, top_b), ft_putstr("pa\n"));
			(rotate_ab(top_a), ft_putstr("ra\n"));
		}
		else
			max_to_top_b(top_b);
	}
	while (is_down_full(*top_a))
		(rev_rotate_ab(top_a), ft_putstr("rra\n"));
}

void	ft_large_sort(t_stack **top_a, t_stack **top_b)
{
	int		*sorted_arr;
	int		size;
	int		div;
	t_ctls	ctls;

	size = ft_stack_size(*top_a);
	if (size <= 150)
		div = 8;
	else
		div = 18;
	ctls.mid = size / 2 - 1;
	ctls.offset = size / div;
	ctls.start = ctls.mid - ctls.offset;
	ctls.end = ctls.mid + ctls.offset;
	sorted_arr = fill_array(*top_a, size);
	while (!is_empty(*top_a))
	{
		push_chunks(top_a, top_b, sorted_arr, ctls);
		update_chunk_ends(&ctls.start, &ctls.end, ctls.offset, size);
	}
	push_back(top_a, top_b, sorted_arr, size - 1);
	free(sorted_arr);
}
