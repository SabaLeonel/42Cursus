/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:40:45 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/08 15:29:22 by lsaba-qu         ###   ########.fr       */
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
			apply("rra", "rra", a, b);
		if (minpos == 1)
		{
			apply("rra", "rra", a, b);
			apply("rra", "rra", a, b);
		}
	}
	else if (minpos > a->size / 2)
	{
		if (minpos == a->size - 2)
			apply("sa", "sa", a, b);
	}
	else if (minpos == 2)
	{
		apply("ra", "ra", a, b);
		minpos = ft_indexof_iarr(a->data, a->size, min);
		if (minpos != a->size - 1)
			apply("sa", "sa", a, b);
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
	if (!ft_isdigit(str[i]) && str[i] != 0)
		error();
	return (res * signe);
}

void	error(void)
{
	ft_putendl_fd("error", 2);
	printf("Hello");
	// ft_garbage_collector(0, 1, 1);
	exit(0);
}
