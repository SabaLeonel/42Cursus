/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/25 02:46:50 by lsaba-qu         ###   ########.fr       */
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
	char	name;
	char	nname;
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

#endif