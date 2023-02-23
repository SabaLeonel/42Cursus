/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:15 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/23 19:08:23 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *a)
{
	int	min;
	int	i;

	i = 0;
	min = a->data[0];
	while (i++ < a->size)
	{
		if (min > a->data[i])
			min = a->data[i];
	}
	return (min);
}

int find_min(t_stack *a)
{
    int min;
    int min_idx;
	int	i;

	min = MAXINT;
	min_idx = -1;
	i = -1;
	while (++i < a->size)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			min_idx = i;
		}
	}
    return min_idx;
}

