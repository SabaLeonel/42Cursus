/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/23 18:49:22 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b, argc, argv);
	sort(&a, &b);
	printf("List sorted \n");
	for (int i = a.size -1; i >= 0; i--) 
	{
    	printf("%d \n", a.data[i]);
	}
	ft_garbage_collector(0, 1, 0);
	return (0);
}
