/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:35:27 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/12 22:54:01 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *tab, int left, int right)
{
	int	i;
	int	j;
	int	piv;

	piv = tab[left];
	i = left + 1;
	j = i;
	while (i <= right)
	{
		if (tab[i] < piv)
		{
			if (i != j)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	if (left != right)
		ft_swap(&tab[left], &tab[j - 1]);
	return (j - 1);
}

void	quick_sort(int *tab, int left, int right)
{
	int	piv_pos;

	if (left < right)
	{
		piv_pos = partition(tab, left, right);
		quick_sort(tab, left, piv_pos - 1);
		quick_sort(tab, piv_pos + 1, right);
	}
}
