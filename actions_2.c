/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:29:07 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:31:22 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rr(t_stack **top_a, t_stack **top_b)
{
	rotate_ab(top_a);
	rotate_ab(top_b);
}

void	rev_rotate_ab(t_stack **top)
{
	t_stack	*last;
	t_stack	*blast;

	if (!top || !*top || !(*top)->next)
		return ;
	last = ft_stacklast(*top);
	blast = ft_before_last(*top);
	last->next = *top;
	*top = last;
	blast->next = 0;
}

void	rev_rotate_rrr(t_stack **top_a, t_stack **top_b)
{
	rev_rotate_ab(top_a);
	rev_rotate_ab(top_b);
}
