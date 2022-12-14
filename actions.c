/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:01:41 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:29:38 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = (*top);
	*top = tmp->next;
	tmp->next = (*top)->next;
	(*top)->next = tmp;
}

void	swap_ss(t_stack **top_a, t_stack **top_b)
{
	swap_ab(top_a);
	swap_ab(top_b);
}

void	push_a(t_stack **top_a, t_stack **top_b)
{
	if (!*top_b)
		return ;
	stack_push(top_a, ft_stacknew((*top_b)->data));
	stack_pop(top_b);
}

void	push_b(t_stack **top_a, t_stack **top_b)
{
	if (!*top_a)
		return ;
	stack_push(top_b, ft_stacknew((*top_a)->data));
	stack_pop(top_a);
}

void	rotate_ab(t_stack **top)
{
	t_stack	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	last = ft_stacklast(*top);
	last->next = *top;
	*top = (*top)->next;
	last->next->next = 0;
}
