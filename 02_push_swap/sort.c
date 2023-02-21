/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/22 00:14:00 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (a->data[1] > a->data[0])
		apply("sa", "sa", a, b);
	if (a->data[2] > a->data[1])
	{
		ft_swap(&a->data[1], &a->data[2]);
		ft_putendl("sa");
		if (a->data[1] > a->data[0])
			apply("sa", "sa", a, b);
	}	
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	find_min_pos(a, &min, &pos);
	while (a->data[a->size - 1] != min)
	{
		if (pos < a->size / 2)
			apply("ra", "ra", a, b);
		else
			apply("rra", "rra", a, b);
	}
	apply("pb", "pb", a, b);
	find_min_pos(a, &min, &pos);
	while (a->data[a->size - 1] != min)
	{
		if (pos < a->size / 2)
			apply("ra", "ra", a, b);
		else
			apply("rra", "rra", a, b);
	}
	apply("pb", "pb", a, b);
	sort_3(a, b);
	while (b->size > 0)
		apply("pa", "pa", a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->size == 0 || a->size == 1)
		return ;
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
	int	i;

	i = -1;
	while (i++ < a->size -1)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
	}
	return (1);
}
