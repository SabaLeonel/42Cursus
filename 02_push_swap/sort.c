/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:00:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/18 17:55:50 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *a)
{
	if (a->data[0] > a->data[1])
		ft_swap(&a->data[0], &a->data[1]);
}

void	sort_3(t_stack *a)
{
	sort2(&a);
}	

void	sort_5(t_stack *a, t_stack *b)
{
	//sort 3 trier les plus petits entre eux
}
