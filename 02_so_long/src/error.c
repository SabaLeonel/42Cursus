/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:48 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/28 18:34:51 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	error(char *message)
{
	if (message)
	{
		ft_putstr_fd("So_long: Error: ", 2);
		ft_putendl_fd(message, 2);	
	}
	exit(EXIT_FAILURE);
	ft_garbage_collector(0, 1, 1); 
}

void	arg_error(int ac)
{
	if (ac < 2)
		error("too few arguments");
	else
		error("too many arguments");
}
