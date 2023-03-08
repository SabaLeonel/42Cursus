/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:00:49 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/08 18:44:21 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;

	i = -1;
	a->data = ft_allok(argc, sizeof(int), 1);
	b->data = ft_allok(argc, sizeof(int), 1);
	while (argv[++i])
	{
		a->data[i] = ft_atoipushswap(argv[i]);
		if (ft_atoipushswap(argv[i]) > MAXINT
			|| ft_atoipushswap(argv[i]) < MININT)
			error();
	}
	a->size = i;
	b->size = 0;
	if (!ft_is_valid(*a))
		error();
	ft_normalizer(a);
}

void	ft_normalizer(t_stack *a)
{
	int	i;
	int	j;
	int	*newtab;
	int	count;

	newtab = ft_allok(a->size, sizeof(int), 1);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		count = 1;
		while (j < a->size)
		{
			if (a->data[i] > a->data[j])
				count ++;
			j ++;
		}
		newtab[i] = count;
		i ++;
	}
	a->data = newtab;
}

// void	parse_one_arg(t_stack *a, t_stack *b, char *argv)
// {
// 	int		i;
// 	char	**tab;

// 	tab = ft_split(argv, ' ');
// 	if (!tab)
// 		error();
// 	i = -1;
// 	a->size = ft_wordcount(argv, ' ');
// 	while (++i < a->size)
// 	{
// 		a->data[a->size - 1 - i] = ft_atoipushswap(tab[i]);
// 		if (ft_atoipushswap(argv[i + 1]) > MAXINT
// 				|| ft_atoipushswap(argv[i + 1]) < MININT)
// 				error();
// 	}
// 	b->size = 0;
// 	ft_free_ppc(tab);
// }
