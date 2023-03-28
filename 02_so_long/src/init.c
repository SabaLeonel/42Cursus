/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/28 23:20:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	generate_map(t_game *game, int fd, char *temp)
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
			if (game->map[y][x] == PLAYER)
			{
				game->playerpos.x = x;
				game->playerpos.y = y;
			}
		}
		y ++;
		temp = ft_get_next_line(fd);
	}
}

void	init_sprites(t_game *game)
{
	game->sprites[ITEMS] = init_image(game, "sprites/sprite_items.xpm");
	game->sprites[WALL] = init_image(game, "sprites/sprite_wall.xpm");
	game->sprites[EXIT] = init_image(game, "sprites/sprite_exit.xpm");
	game->sprites[PLAYER] = init_image(game, "sprites/sprite_player.xpm");
	game->sprites[EMPTY] = init_image(game, "sprites/sprite_empty.xpm");
}

t_canvas	init_image(t_game *game, char *filepath)
{
	t_canvas	img;

	img.img = mlx_xpm_file_to_image(game->window.mlx, filepath, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img,
			&img.pixel_bits, &img.line_length, &img.endian);
	return (img);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++ y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			mlx_put_image_to_window(game->window.mlx,
				game->window.win, game->sprites[EMPTY].img, x * 96, y * 96);
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->sprites[game->map[y][x]].img, x * 96, y * 96);
		}
	}
	return (0);
}
