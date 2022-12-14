/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:56:54 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 15:27:31 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	execute_action(t_stack **top_a, t_stack **top_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_ab(top_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap_ab(top_b);
	else if (!ft_strcmp(line, "ss\n"))
		swap_ss(top_a, top_b);
	else if (!ft_strcmp(line, "ra\n"))
		rotate_ab(top_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_ab(top_b);
	else if (!ft_strcmp(line, "rr\n"))
		rotate_rr(top_a, top_b);
	else if (!ft_strcmp(line, "rra\n"))
		rev_rotate_ab(top_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rev_rotate_ab(top_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rev_rotate_rrr(top_a, top_b);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(top_a, top_b);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(top_a, top_b);
	else
		(free(line), _ft_putstr_fd("Error\n", 2));
}

void	check_operations(t_stack **top_a, t_stack **top_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_action(top_a, top_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (is_sorted(*top_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*top_a;
	t_stack	*top_b;

	if (ac < 2)
		_ft_putstr_fd("Error\n", 2);
	if (!stack_fill(ac, av, &top_a))
		_ft_putstr_fd("Error\n", 2);
	check_operations(&top_a, &top_b);
	return (0);
}
