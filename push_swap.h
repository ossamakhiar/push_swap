/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:53:00 by okhiar            #+#    #+#             */
/*   Updated: 2022/12/14 13:46:28 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define __INT_MAX 2147483647
# define __INT_MIN 2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ctls
{
	int	mid;
	int	offset;
	int	start;
	int	end;
}	t_ctls;

void	ft_putstr(char *str);
void	_ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
int		ft_is_digits(char *str);

/*Stack Implementation*/
t_stack	*ft_stacknew(int data);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_before_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	stack_push(t_stack **top, t_stack *stack);
int		stack_fill(int ac, char **av, t_stack **top);
void	stack_pop(t_stack **top);
void	display(t_stack *stack);
int		ft_get_min(t_stack *stack);
int		ft_get_max(t_stack *stack);
int		is_empty(t_stack *stack);
int		ft_get_index(t_stack *stack, int key);
int		ft_get_index_(t_stack *stack, int min, int max);

/*Actions*/
void	swap_ab(t_stack **top);
void	swap_ss(t_stack **top_a, t_stack **top_b);
// void    push_swap(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack **top_a, t_stack **top_b);
void	push_b(t_stack **top_a, t_stack **top_b);
void	rotate_ab(t_stack **top);
void	rotate_rr(t_stack **top_a, t_stack **top_b);
void	rev_rotate_ab(t_stack **top);
void	rev_rotate_rrr(t_stack **top_a, t_stack **top_b);

/*Sort*/
int		is_sorted(t_stack *stack);
/**
 * @brief QuickSort is a Divide and Conquer algorithm. 
 * It picks the first element as a pivot and partitions 
 * the given array around the picked pivot
 * The key process in quickSort is a partition(). The target of partitions is,
 * given an array and first of an array as the pivot, 
 * put pivot at its correct position in a sorted array and put all smaller 
 * elements (smaller than pivot) before pivot,
 * and put all greater elements (greater than pivot) after pivot. T = O(n log(n)
 * 
 * @param tab 
 * @param left 
 * @param right 
 */
void	quick_sort(int *tab, int left, int right);
void	sort_small_stack(t_stack **top_a, t_stack **top_b, int size);

/**** Large Sort ****/

/**
 * @brief this function is used to move the biggest element
 * of the stack to the top of it, which choose between use 
 * ra or rra using the index of the big element and check if
 * it greater or less than the mid point of the stack
 * 
 * @param top_b double pointer of the stack to modifie
 * smoothly
 */
void	max_to_top_b(t_stack **top_b);
void	ft_large_sort(t_stack **top_a, t_stack **top_b);

/**
 * @brief this function will traverse throught the stack, and
 * give us the index of the first seen element 
 * that is on the range [min, max]
 * 
 * @param stack the stack to be traversed
 * @param min the min value
 * @param max the max value
 * @return int index of the first seen element
 */
int		ft_get_index_(t_stack *stack, int min, int max);

/**
 * @brief Check if there are elements that we push and rotate it
 * in the bottom of stack A
 * @param stack the pointer to the stack to traverse throught it
 * @return int if there are elements return value 1, otherwise return 0
 */
int		is_down_full(t_stack *stack);

/**
 * @brief this function will check if the Current biggest value is 
 * exists on Stack B or we did push it to the bottom of the
 * stack A
 * 
 * @param stack the stack that we check (In this case of course is B)
 * @param max The current largest value
 * @return int 
 */
int		check_max_on_b(t_stack *stack, int max);

/**
 * @brief get the data of the bottom (last element) on the stack
 * 
 * @param stack stack pointer to define
 * @return int the value of the bottm element
 */
int		ft_bottom_data(t_stack *stack);

/*BONUS*/
char	*get_next_line(int fd);

#endif
