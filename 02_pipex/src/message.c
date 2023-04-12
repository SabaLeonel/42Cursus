/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/12 14:42:45 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	message(char *msg, int mode)
{
	if (mode == 0 && msg)
	{
		ft_putendl_fd(msg, 1);
		exit(mode);
	}
	if (mode == 1 && msg)
	{
		ft_putstr_fd("Pipex: Error: ", 1);
		ft_putendl_fd(msg, 1);
		exit(mode);
	}
}
