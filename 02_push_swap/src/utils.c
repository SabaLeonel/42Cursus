/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:40:45 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/10 12:43:05 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos(int *minpos, int *maxpos, int *pivotpos, t_stack *a)
{
	*minpos = ft_indexof_iarr(a->data, a->size, *minpos);
	*maxpos = ft_indexof_iarr(a->data, a->size, *maxpos);
	*pivotpos = ft_indexof_iarr(a->data, a->size, *pivotpos);
}

void	push_min_to_front(t_stack *a, t_stack *b, int minpos, int min)
{
	if (minpos < a->size / 2)
	{
		if (minpos == 0)
			apply("rra", a, b);
		if (minpos == 1)
		{
			apply("rra", a, b);
			apply("rra", a, b);
		}
	}
	else if (minpos > a->size / 2)
	{
		if (minpos == a->size - 2)
			apply("sa", a, b);
	}
	else if (minpos == 2)
	{
		apply("ra", a, b);
		minpos = ft_indexof_iarr(a->data, a->size, min);
		if (minpos != a->size - 1)
			apply("sa", a, b);
	}
}

long int	ft_atoipushswap(const char *str)
{
	long int	i;
	long int	res;
	long int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i ++;
	}
	if ((!ft_isdigit(str[i]) && str[i] != 0)
		|| (str[0] == '-' && str[1] == '\0')
		|| (str[0] == '+' && str[1] == '\0'))
		error();
	return (res * signe);
}

void	error(void)
{
	ft_putendl_fd("Error", 2);
	ft_garbage_collector(0, 1, 1);
}
