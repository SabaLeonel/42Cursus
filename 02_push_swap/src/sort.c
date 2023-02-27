/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/27 00:48:00 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack *a, t_stack *b)
{

	int minpos;
	int maxpos;
	int pivotpos;

	minpos = ft_find_min(a->data, a->size);
	maxpos = ft_find_max(a->data, a->size);
	pivotpos = ft_find_pivot(a->data, a->size);
	minpos = ft_indexof_iarr(a->data, a->size, minpos);
	maxpos = ft_indexof_iarr(a->data, a->size, maxpos);
	pivotpos = ft_indexof_iarr(a->data, a->size, pivotpos);
	if (minpos == 1 && maxpos == 0 && pivotpos == 2)
		apply("sa", "sa", a, b);
	else if (minpos == 1 && maxpos == 2 && pivotpos == 0)
		apply("ra", "ra", a, b);
	else if (minpos == 0 && maxpos == 1 && pivotpos == 2)
		apply("rra", "rra", a, b);
	else if (minpos == 2 && maxpos == 1 && pivotpos == 0)
	{
		apply("sa", "sa", a, b);
		apply("ra", "ra", a, b);
	}
	else if (minpos == 0 && maxpos == 2 && pivotpos == 1)
	{
		apply("sa", "sa", a, b);
		apply("rra", "rra", a, b);
	}
}

void	send_smallest_to_b(t_stack *a, t_stack *b)
{
	int min;
	int minpos;

	min = ft_find_min(a->data, a->size);
	minpos = ft_indexof_iarr(a->data, a->size, min);
	if (minpos < a->size / 2)
	{
		if (minpos == 0)
			apply("rra", "rra", a, b);
		if (minpos == 1)
		{
			apply("rra", "rra", a, b);
			apply("rra", "rra", a, b);
		}
	}
	else if (minpos > a->size / 2)
	{
		if (minpos == a->size - 2)
			apply("sa", "sa", a, b);
	}
	else if (minpos == 2)
	{
		apply("ra", "ra", a, b);
		minpos = ft_indexof_iarr(a->data, a->size, min);
		if (minpos != a->size-1)
			apply("sa", "sa", a, b);
	}
	apply("pb", "pb", a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		send_smallest_to_b(a, b);
	send_smallest_to_b(a, b);
	sort_3(a, b);
	apply("pa", "pa", a, b);
	apply("pa", "pa", a, b);
}

void	sort(t_stack *a, t_stack *b)
{

	if (is_sorted(a) || a->size == 0 || a->size == 1)
		return;
	else if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
			apply("sa", "sa", a, b);
	}
	else if (a->size == 3)
		sort_3(a, b);
	else if (a->size == 4 || a->size == 5)
		sort_5(a, b);
}

int	is_sorted(t_stack *a)
{
	int i;

	i = -1;
	while (i++ < a->size - 1)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
	}
	return (1);
}
