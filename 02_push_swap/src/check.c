/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:00:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/07 19:26:03 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	int	i;

	i = -1;
	ft_swap(&a->data[0], &a->data[a->size - 1]);
	while (i++ < a->size - 3)
		ft_swap(&a->data[a->size -1 - i], &a->data[a->size -2 - i]);
}

void	rrotate(t_stack *a)
{
	int	i;

	i = -1;
	ft_swap(&a->data[0], &a->data[a->size - 1]);
	while (++i < a->size -2)
	{
		ft_swap(&a->data[i], &a->data[i + 1]);
	}
}

void	apply(char *action, char *print, t_stack *a, t_stack *b)
{
	if ((!ft_strcmp(action, "sa") || !ft_strcmp(action, "ss")) && a->size > 1)
		ft_swap(&a->data[a->size - 2], &a->data[a->size - 1]);
	if ((!ft_strcmp(action, "sb") || !ft_strcmp(action, "ss")) && b->size > 1)
		ft_swap(&b->data[b->size - 2], &b->data[b->size - 1]);
	if (!ft_strcmp(action, "pa") && b->size)
		ft_swap(&a->data[a->size++], &b->data[--b->size]);
	if (!ft_strcmp(action, "pb") && a->size)
		ft_swap(&a->data[--a->size], &b->data[b->size++]);
	if ((!ft_strcmp(action, "ra") || !ft_strcmp(action, "rr")) && a->size > 1)
		rotate(a);
	if ((!ft_strcmp(action, "rb") || !ft_strcmp(action, "rr")) && b->size > 1)
		rotate(b);
	if ((!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrr")) && a->size > 1)
		rrotate(a);
	if ((!ft_strcmp(action, "rrb") || !ft_strcmp(action, "rrr")) && b->size > 1)
		rrotate(b);
	if (print)
		ft_putendl_fd(print, 1);
}

int	ft_is_valid(t_stack a)
{
	if (ft_doublons_ia(a.data, a.size))
		error();
	return (1);
}
