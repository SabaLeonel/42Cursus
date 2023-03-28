/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:12:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/29 00:12:17 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_frame(t_anim *c)
{
	if (++c->timer >= c->time_to_change)
	{
		c->timer = 0;
		if (++c->current_frame >= c->frame_amount)
			c->current_frame = 0;
	}
}

int	key_hook(t_game *game)
{
	t_vector	new_pos;
	static		int counter = 0;
	int			i;

	i = -1;
	if (++counter < 1000)
		return (0);
	while (++i < 5)
		set_frame(&game->sprites[i]);
	draw_map(game);
	counter = 0;
	new_pos = game->player_pos;
	if (game->keys[KEYCODE_A])
		new_pos.x -= 1;
	else if (game->keys[KEYCODE_S])
		new_pos.y += 1;
	else if (game->keys[KEYCODE_D])
		new_pos.x += 1;
	else if (game->keys[KEYCODE_W])
		new_pos.y -= 1;
	else
	{
		return (0);
	}
	hook_move(new_pos, game);
	return (0);
}

int	hook_move(t_vector new_pos, t_game *game)
{
	if (game->map[new_pos.y][new_pos.x] == WALL
		|| (game->map[new_pos.y][new_pos.x] == EXIT &&
			game->coll_count != game->collectible))
		return (0);
	game->map[game->player_pos.y][game->player_pos.x] = 0;
	if (game->map[new_pos.y][new_pos.x] == COLLECTIBLE)
		game->coll_count++;
	if (game->map[new_pos.y][new_pos.x] == EXIT)
	{
		printf("you won\n");
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
