/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:17 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:57:50 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void	stack_push(t_stack **top, t_stack *stack)
{
	if (!(stack && top))
		return ;
	stack->next = *top;
	*top = stack;
}

void	stack_pop(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	tmp = 0;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}
