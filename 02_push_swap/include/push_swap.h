/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/02 16:29:22 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*data;
	int		*index;
	int		size; 
}	t_stack;

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv);
int		ft_is_valid(t_stack a, char **argv);
void	rrotate(t_stack *a);
void	rotate(t_stack *a);
void	apply(char *action, char *print, t_stack *a, t_stack *b);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
int		main(int argc, char **argv);
void	parse_one_arg(t_stack *a, t_stack *b, char **tab, char **argv);
void	find_pos(int minpos, int maxpos, int pivotpos, t_stack *a);
void	push_min_to_front(t_stack *a, t_stack *b, int minpos, int min);
void	radix_sort(t_stack *a, t_stack *b);
void	ft_normalizer(t_stack *a);

#endif