/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/19 23:47:12 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	int		i;
	t_stack	b;

	printf("list : \n");
	ft_init_stack(&a, &b, argc, argv);
	for (i = a.size -1; i >= 0; i--)
	{
		printf("\nNum : %i - pos : %i\n ", a.data[i], i);
	}
	sort_5(&a, &b);
	printf("\nlist sorted : \n");
	for (i = a.size -1; i >= 0; i--)
	{
		printf("\nNum : %i - pos : %i\n ", a.data[i], i);
	}
	ft_garbage_collector(0, 1, 0);
	return (0);
}
