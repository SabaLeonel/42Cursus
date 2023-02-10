/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/10 09:35:07 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	argc_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}


void free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = 0;
		}
		i ++;
	}
	tab = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b, argc, argv);
	return (0);
}
