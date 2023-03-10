/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:22:09 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/10 12:10:33 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_num;
	int	num;
	int	max_bits;

	max_num = a->size - 1;
	max_bits = 0;
	i = -1;
	while ((max_num >> max_bits) != 0)
		max_bits ++;
	max_num = a->size;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < max_num)
		{
			num = a->data[a->size -1];
			if (((num >> i) & 1) == 1)
				apply("ra", a, b);
			else
				apply("pb", a, b);
		}
		connect_numbers(a, b);
	}
}

void	connect_numbers(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (b ->size != 0)
		apply("pa", a, b);
}
