/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:44 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 19:35:06 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *path)
{
	int len;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(&path[len - 4], ".ber"))
		error("invalid file extension");
}

int	check_elements(char c, t_game *game)
{
	if (c == '0')
		return (EMPTY);
	else if (c == 'C' && ++game->item)
		return (ITEMS);
	else if (c == 'E' && ++game->exit)
		return (EXIT);
	else if (c == 'P' && ++game->players)
		return (PLAYERS);
	else if (c == '1')
		return (WALL);
	else
		error("invalid character or charaters");
	return (-1);
}
