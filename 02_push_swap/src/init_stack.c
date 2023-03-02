/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:00:49 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/02 18:07:45 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	char	**tabsplit;

	i = -1;
	tabsplit = NULL;
	a->data = ft_allok(argc, sizeof(int), 1);
	b->data = ft_allok(argc, sizeof(int), 1);
	if (argc == 2)
	{
		parse_one_arg(a, b, tabsplit, argv);
	}
	else if (argc > 2)
	{
		while (++i < argc - 1)
		{
			a->data[argc - 2 - i] = ft_atoilong(argv[i + 1]);
			if (a->data[argc - 2 - i] > MAXINT
				|| a->data[argc - 2 - i] < MININT)
				i = MAXINT; 
		}
		a->size = argc - 1;
		b->size = 0;
	}
	if (!ft_is_valid(*a, argv) || i == MAXINT)
		ft_garbage_collector(0, 1, 1);
	ft_normalizer(a);
}

void	ft_normalizer(t_stack *a)
{
	int	i;
	int j;
	int	*newtab;
	int	count;


	newtab = ft_allok(a->size, sizeof(int), 1);
	i = 0;
	printf("\n------INIT-------\n");
	for (i =0; i < a->size; i ++)
		printf("\n a->data[%i] : %i\n",i, a->data[i]);
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
	for (i =0; i < a->size; i ++)
		printf("\n newtab[%i] : %i\n",i, newtab[i]);
	a->data = newtab;
	printf("\n------COPY DONE-------\n");
	for (i =0; i < a->size; i ++)
		printf("\n a->data[%i] : %i\n",i, a->data[i]);
}

void	parse_one_arg(t_stack *a, t_stack *b, char **tab, char **argv)
{
	int	i;

	i = -1;
	a->size = ft_wordcount(argv[1], ' ');
	tab = ft_allok(a->size, sizeof(int), 1);
	tab = ft_split(argv[1], ' ');
	while (++i < a->size)
	{
		a->data[a->size - 1 - i] = ft_atoilong(tab[i]);
		if (a->data[a->size - 1 - i] > MAXINT
			|| a->data[a->size - 1 - i] < MININT)
			i = MAXINT;
	}
	b->size = 0;
}
