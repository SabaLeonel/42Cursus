/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:12:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/18 18:13:52 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *game)
{
	t_vector	new_pos;

	new_pos = game->player_pos;
	if (key == KEYCODE_A)
		new_pos.x -= 1;
	else if (key == KEYCODE_S)
		new_pos.y += 1;
	else if (key == KEYCODE_D)
		new_pos.x += 1;
	else if (key == KEYCODE_W)
		new_pos.y -= 1;
	else
		return (0);
	if (game->map[new_pos.y][new_pos.x] == WALL
		|| (game->map[new_pos.y][new_pos.x] == EXIT && game->coll_count != game->collectible))
		return (0);
	game->map[game->player_pos.y][game->player_pos.x] = 0;
	if (game->map[new_pos.y][new_pos.x] == COLLECTIBLE)
		game->coll_count++;
	if (game->map[new_pos.y][new_pos.x] == EXIT)
	{
		printf("zyou won\n");
		game->player_pos = new_pos;
		draw_map(game);
		return (0);
	}
	game->map[new_pos.y][new_pos.x] = PLAYER;
	game->player_pos = new_pos;
	draw_map(game);
	game->move_count++;
	printf("you did %i steps\n", game->move_count);
	return (0);
}
