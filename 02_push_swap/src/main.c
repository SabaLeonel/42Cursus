/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/08 18:42:48 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			error();
		ft_init_stack(&a, &b, ft_wordcount(argv[1], ' '), tmp);
		ft_free_pp((void **)tmp);
	}
	else if (argc > 2)
	{
		ft_init_stack(&a, &b, argc, argv + 1);
	}
	sort(&a, &b);
	ft_garbage_collector(0, 1, 0);
	return (0);
}
