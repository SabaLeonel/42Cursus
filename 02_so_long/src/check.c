/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:36:02 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/18 18:13:18 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_min_amount(t_game *game)
{
	if (game->players != 1)
		error("invalid player amount");
	if (game->exit != 1)
		error("invalid exit amount");
	if (game->collectible < 1)
		error("invalid collectible amount");
}

void check_wall(t_game *game)
{
	int i;

	i = -1;
	while(++i < game->size.x)
	{
		if (game->map[0][i] != WALL)
			error("not a wall");
		if (game->map[game->size.y -1][i] != WALL)
			error("not a wall");
	}
	i = -1;
	while (++i < game->size.y)
	{
		if (game->map[i][0] != WALL)
			error("not a wall");
		if (game->map[i][game->size.x -1] != WALL)
			error("not a wall");
	}
}

void	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(&path[len -4], ".ber"))
		error("invalid filetype");
}

int	check_elements(char c, t_game *game)
{
	if (c == '0')
		return (EMPTY);
	else if (c == '1')
		return (WALL);
	else if (c == 'C' && ++game->collectible)
		return (COLLECTIBLE);
	else if (c == 'E' && ++game->exit)
		return (EXIT);
	else if (c == 'P' && ++game->players)
		return (PLAYER);
	else
		error("invalid caratere");
	return (-1);	
}