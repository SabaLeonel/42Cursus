/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:13:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/25 17:17:20 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_max(int *tab, int size)
{
	int max;
	int i;

	i = -1;
	max = MININT;
	while (++i < size)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}