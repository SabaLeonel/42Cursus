/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:35:39 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/09 16:12:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	argc_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

static void	big_free(t_head_tail *stack_a, char **str)
{
	if (str)
		free_tab(str);
	free_list(&stack_a->head);
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

static void free_tab(char **tab)
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

static void	free_list(t_stack **first)
{
	t_stack	*temp;

	if (!*first)
		return ;
	while (*first)
	{
		temp = (*first)->next;
		free(*first);
		*first = temp;
	}
	*first = 0;
}

void	start(int argc, char **argv,t_head_tail *stack_a, t_head_tail *stack_b)
{
	char	**str;
	int		argc_c;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		argc_c = argc_count(str);
		if (init_stack_a(argc_c, str, stack_a, 0) == 0)
			big_free(stack_a, stack_b);
	}
	else if (argc >= 3)
	{
		str = 0;
		if (init_stack_a(argc_c, str, stack_a, 0) == 0)
			big_free(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_head_tail	stack_a;
	t_head_tail	stack_b;

	if (argc < 2)
		exit(0);
	start(argc, argv, &stack_a, &stack_b); 
}
