/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/17 17:36:41 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	int		i;
	t_stack	b;

	printf("list :");
	ft_init_stack(&a, &b, argc, argv);
	for (i = 0; i < a.size; i++)
	{
		printf("%i", a.data[i]);
	}
	ft_garbage_collector(0, 1, 0);
	return (0);
}
