/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:00:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/10 15:06:36 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid(t_stack a, char **argv)
{
	if (ft_doublons_ia(a.data, a.size))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (ft_all_are_num(&argv[1]))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	return (1);
}