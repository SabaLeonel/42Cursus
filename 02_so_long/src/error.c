/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:38:50 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/17 19:44:29 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	if (message)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd("so_long: ", 2);
		ft_putendl_fd(message, 2);
	}
	ft_garbage_collector(0, 1, 1);
}

