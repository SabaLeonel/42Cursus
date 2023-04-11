/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/11 18:18:45 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print(char *message, int mode)
{
	if (mode == 1 && message)
	{
		ft_putstr_fd("Pipex: Error: ", 1);
		ft_putendl_fd(message, 1);
		exit(mode);
	}
	if (mode == 0 && message)
	{
		ft_putendl_fd(message, 1);
		exit(mode);
	}
}