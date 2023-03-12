/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/12 23:29:42 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (a->data[2] == 3)
		apply("ra", a, b);
	else if (a->data[1] == 3)
		apply("rra", a, b);
	if (a->data[2] == 2)
		apply("sa", a, b);
}

void	send_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	minpos;

	min = ft_find_min(a->data, a->size);
	minpos = ft_indexof_iarr(a->data, a->size, min);
	push_min_to_front(a, b, minpos, min);
	apply("pb", a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		send_smallest_to_b(a, b);
	send_smallest_to_b(a, b);
	if (a->data[2] == 5)
		apply("ra", a, b);
	else if (a->data[1] == 5)
		apply("rra", a, b);
	if (a->data[2] == 4)
		apply("sa", a, b);
	apply("pa", a, b);
	apply("pa", a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->size == 0 || a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (a->data[1] > a->data[2])
			apply("sa", a, b);
	}
	else if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 4 || a->size == 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (i++ < a->size - 2)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
	}
	return (1);
}
