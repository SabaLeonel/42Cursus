/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:40:45 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/27 23:35:20 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos(int minpos, int maxpos, int pivotpos, t_stack *a)
{
	minpos = ft_indexof_iarr(a->data, a->size, minpos);
	maxpos = ft_indexof_iarr(a->data, a->size, maxpos);
	pivotpos = ft_indexof_iarr(a->data, a->size, pivotpos);
}

void	push_min_to_front(t_stack *a, t_stack *b, int minpos, int min)
{
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
		if (minpos != a->size - 1)
			apply("sa", "sa", a, b);
	}
}
