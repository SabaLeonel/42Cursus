/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/20 23:19:55 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->data[0] < a->data[1])
		ft_swap(&a->data[0], &a->data[1]);
}

void	sort_3(t_stack *a)
{
	if (a->data[1] > a->data[0])
		ft_swap(&a->data[0], &a->data[1]);
	if (a->data[2] > a->data[1])
	{
		ft_swap(&a->data[1], &a->data[2]);
		if (a->data[1] > a->data[0])
			ft_swap(&a->data[1], &a->data[0]);
	}	
}	

void	sort_5(t_stack *a, t_stack *b)
{
	apply("pb", "pb", a, b);
	apply("pb", "pb", a, b);
	sort_3(a);
	sort_2(b);
	apply("pa", "pa", a, b);
	apply("pa", "pa", a, b);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->size == 0 || a->size == 1)
		return ;
	else if (a->size == 2)
		sort_2(a);
	else if (a->size  == 3)
		sort_3(a);
	else if (a->size  == 4)
		sort_5(a, b);
	else if (a->size  == 5)
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