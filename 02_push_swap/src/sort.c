/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/25 17:30:46 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack *a, t_stack *b)
{

	int	minpos;
	int maxpos;
	int pivot;

	minpos = ft_find_min(a->data, a->size);
	maxpos = ft_find_max(a->data, a->size);	
	if (minpos != a->data[0] || minpos != a->data[1])
	minpos = ft_indexof_iarr(a->data, a->size, minpos);
	maxpos = ft_indexof_iarr(a->data, a->size, maxpos);
	if (NULL)
	{
		apply("sa", "sa", a, b);
		apply("ra", "ra", a, b);
	}
	else if (NULL)
		apply("sa", "sa", a, b);
	else if (NULL)
		apply("rra", "rra", a, b);
	else if (void)
		apply("ra", "ra", a, b);
	else if (void)
	{
		apply("sa", "sa", a, b);
		apply("rra", "rra", a, b);
	}
}

void send_smallest_to_b(t_stack *a, t_stack *b)
{
	int min;

	min = ft_find_min(a->data, a->size);
	if (a->data[0] == min)
		apply("rra", "rra", a, b);
	if (a->data[a->size - 2] == min)
		apply("sa", "sa", a, b);
	if (a->data[a->size - 3] == min)
		ft_swap(&a->data[a->size - 3], &a->data[a->size - 1]);
	if (a->data[a->data[1]] == min)
	{
		ft_swap(&a->data[1], &a->data[a->size - 1]);
	}
	if (a->data[a->size - 1] == min)
		apply("pb", "pb", a, b);
}

void sort_5(t_stack *a, t_stack *b)
{
	// if data.size = 5 faire 2x lop juste en bas
	// 2 push chiffre plus bas dans le b
	if (a->size == 5)
		send_smallest_to_b(a, b);
	send_smallest_to_b(a, b);
	sort_3(a, b);
	apply("pa", "pa", a, b);
	apply("pa", "pa", a, b);
}

void sort(t_stack *a, t_stack *b)
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

int is_sorted(t_stack *a)
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
