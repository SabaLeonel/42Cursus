/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:28:13 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/21 23:41:43 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_min_pos(int *arr, int len)
{
	int	min;
	int	min_pos;
	int	i;

	i = 1;
	min = arr[0];
	min_pos = 0;
	while (i < len)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
