/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:00:49 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/07 18:30:50 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;

	i = -1;
	a->data = ft_alloc(argc, sizeof(int), error);
	b->data = ft_alloc(argc, sizeof(int), error);
	if (argc == 2)
		parse_one_arg(a, b, argv[1]);
	else if (argc > 2)
	{
		while (++i < argc - 1)
		{
			a->data[argc - 2 - i] = ft_atoipushswap(argv[i + 1]);
			if (a->data[argc - 2 - i] > MAXINT
				|| a->data[argc - 2 - i] < MININT)
				error();
		}
		a->size = argc - 1;
		b->size = 0;
	}
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

	newtab = ft_alloc(a->size, sizeof(int), error);
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

void	parse_one_arg(t_stack *a, t_stack *b, char *argv)
{
	int		i;
	char	**tab;

	tab = ft_split(argv, ' ');
	i = -1;
	a->size = ft_wordcount(argv, ' ');
	while (++i < a->size)
	{
		a->data[a->size - 1 - i] = ft_atoipushswap(tab[i]);
		if (a->data[a->size - 1 - i] > MAXINT
			|| a->data[a->size - 1 - i] < MININT)
			error();
	}
	ft_freepp(tab);
	b->size = 0;
}
