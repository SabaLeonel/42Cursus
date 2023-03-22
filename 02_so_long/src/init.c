/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/22 19:36:06 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void		generate_map(t_game *game, int fd, char *temp)
{
	int	x;
	int	y;

	y = 0;
	while (temp)
	{
		if ((int)ft_strlen(temp) - 1 != game->size.x)
			error("lines are not the same size");
		x = -1;
		game->map[y] = ft_allok(game->size.x, sizeof(int), 1);
		while (++x < game->size.x)
		{
			game->map[y][x] = check_elements(temp[x], game);
			if (game->map[y][x] == PLAYERS)
			{
				game->playerpos.x = x;
				game->playerpos.y = y;
			}
		}
		y ++;
		temp = ft_get_next_line(fd);
	}
}
