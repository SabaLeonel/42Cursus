/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:15 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/21 23:49:24 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_pos(t_stack *a, int *min, int *pos)
{
	int	i;

	i = 1;
	if (a->size == 0)
		return ;
	*min = a->data[0];
	*pos = 0;
	while (i < a->size)
	{
		if (a->data[i] < *min)
		{
			*min = a->data[i];
			*pos = i;
		}
		i++;
	}
}
