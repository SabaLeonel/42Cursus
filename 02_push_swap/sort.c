/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/20 00:14:12 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->data[0] > a->data[1])
		ft_swap(&a->data[0], &a->data[1]);
}

void	sort_3(t_stack *a)
{
	if (a->data[a->size -1] > a->data[a->size -2])
		sort_2(a);
	if (a->data[0] < a->data[a->size -2])
	{
		ft_swap(&a->data[0], &a->data[a->size -2]);
		if (a->data[a->size -1] > a->data[a->size -2])
			sort_2(a);
	}	
}	

void	sort_5(t_stack *a, t_stack *b)
{
	int i;
	apply("pb", "pb",a, b);
	apply("pb", "pb",a, b);
	for (i = a->size -1; i >= 0; i--)
	{
		printf("\nNum : %i - pos : %i\n ", a->data[i], i);
	}
	sort_3(a);
	apply("pa", "pa", a, b);
	printf("\n after PA \n");
	for (i = a->size -1; i >= 0; i--)
	{
		printf("\nNum : %i - pos : %i\n ", a->data[i], i);
	}

	apply("ra", "ra", a, b);
	
	for (i = a->size -1; i >= 0; i--)
	{
		printf("\nNum : %i - pos : %i\n ", a->data[i], i);
	}
	apply("pa", "pa", a, b);
}
