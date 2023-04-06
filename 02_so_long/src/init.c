/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:31:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/04/06 16:16:23 by lsaba-qu         ###   ########.fr       */
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
			error("Error initializing the map");
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
		free(temp);
		y ++;
		temp = ft_get_next_line(fd);
	}
}

void	init_sprites(t_game *game)
{
	game->sprites[WALL] = init_image(game->window.mlx,
			"sprites/sprite-wall.xpm");
	game->sprites[EXIT] = init_image(game->window.mlx,
			"sprites/sprite-exit.xpm");
	game->sprites[EMPTY] = init_image(game->window.mlx,
			"sprites/sprite-empty.xpm");
	game->sprites[PLAYER] = init_image(game->window.mlx,
			"sprites/sprite-player-gs-stand.xpm");
	game->sprites[ITEMS] = init_image(game->window.mlx,
			"sprites/sprite-items.xpm");
}

t_canvas	init_image(void *mlx, char *filepath)
{
	t_canvas	img;

	img.img = mlx_xpm_file_to_image(mlx, filepath, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img,
			&img.pixel_bits, &img.line_length, &img.endian);
	return (img);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->sprites[EMPTY].img, x * 96, y * 96);
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->sprites[game->map[y][x]].img, x * 96, y * 96);
		}
	}
	return (0);
}
