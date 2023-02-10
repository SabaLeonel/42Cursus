/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:00:49 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/10 15:36:53 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = -1;
	a->name = 'a';
	b->name = 'b';
	a->nname = 'b';
	b->nname = 'a';
	a->data = ft_allok(argc, sizeof(int), 1);
	b->data = ft_allok(argc, sizeof(int), 1);
	while (++i < argc -1)
	{
		a->data[argc - 2 - i] = ft_atoli(argv[i + 1]);
		if (a->data[argc - 2 - i] > MAXINT
			|| a->data[argc - 2 - i] < MININT)
			i = MAXINT;
	}
	a->size = argc - 1;
	b->size = 0;
	if (!ft_is_valid(*a, argv) || i == MAXINT)
		ft_garbage_collector(0, 1, 1);
}
