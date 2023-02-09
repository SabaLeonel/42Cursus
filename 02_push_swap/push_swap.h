/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/09 15:58:36 by lsaba-qu         ###   ########.fr       */
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
	int				data;
	int				data1;
	int				pos;
	struct s_stack	*last;
	struct s_stack	*next;	
}	t_stack;

typedef struct s_head_tail
{
	t_stack	*head;
	t_stack	*tail;
}	t_head_tail;

int		ft_initStack(int *tab, int size, char type);

#endif
