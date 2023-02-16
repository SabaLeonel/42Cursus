/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/16 16:09:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

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
void	apply(t_stack *a, t_stack *b, char *action, char *print);

#endif