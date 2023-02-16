/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:00:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/16 17:28:48 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void	rotate(t_stack *a)
{
	int	i;

	i = -1;
	ft_swap(&a->data[0], &a->data[a->size - 1]);
	while (i++ < a->size - 2)
		ft_swap(&a->data[a->size -1 -i], &a->data[a->size -2 -i]);
}

void	counter (int mode)
{
	static int	count;

	if(mode)
	{
		ft_putnbrendl(count);
		return ;
	}
	else
		count++;
}

void	apply(t_stack *a, t_stack *b, char *action, char *print)
{
	if (!ft_strcmp(action, "sa") || !ft_strcmp(action, "ss") && a->size > 1)
		ft_swap(&a->data[a->size - 2], &a->data[a->size -1]);
	if (print)
		ft_putendl(print);
	counter(0);
}

int	ft_is_valid(t_stack a, char **argv)
{
	if (ft_doublons_ia(a.data, a.size))
	{
		ft_putendl("Error");
		return (0);
	}
	if (ft_all_are_num(&argv[1]))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}