/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:00:49 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/09 16:18:59 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(int argc, char **argv, t_head_tail *stack_a, int start)
{
	t_stack	*new;
	t_stack	*n;
	int		i;
	i = start;
	new = init_lst(argv[i++], stack_a->head);
	if (!new)
		return (0);
	stack_a->head = new;
	while (i != argc)
	{
		n = init_lst(argv[i], stack_a->head);
		if (!n)
			return (0);
		new->next = n;
		n->last = new;
		new = n;
		i++;
	}
	stack_a->tail = new;
	return (1);
}