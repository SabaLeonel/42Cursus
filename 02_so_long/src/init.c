/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:21:37 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/18 18:22:49 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *game)
{
	game->sprites[WALL] = ft_init_image(game->window.mlx, "sprites/sprite_wall.xpm");
	game->sprites[EXIT] = ft_init_image(game->window.mlx, "sprites/sprite_exit.xpm");
	game->sprites[EMPTY] = ft_init_image(game->window.mlx, "sprites/sprite_empty.xpm");
	game->sprites[PLAYER] = ft_init_image(game->window.mlx, "sprites/sprite_player.xpm");
	game->sprites[COLLECTIBLE] = ft_init_image(game->window.mlx, "sprites/sprite_collectible.xpm");
}


void	generate_map(t_game *game, int fd, char *temp)
{
    int x;
	int	y ;

	y =0;
	while (temp)
	{
		if ((int)ft_strlen(temp) - 1 != game->size.x) // check si la longeur est la meme entre la premiere ligne et les autres
			error("les lignes sont pas a la meme taille");
		x = -1;
		game->map[y] = ft_allok(game->size.x, sizeof(int), 1);
		while (++x < game->size.x)
		{
			game->map[y][x] = check_elements(temp[x], game);
			if (game->map[y][x] == PLAYER)
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
		}
		y ++;
		temp = ft_get_next_line(fd);
	}
}

t_canvas	ft_init_image(void *mlx, char *filename)
{
	t_canvas	cvs;

	cvs.img = mlx_xpm_file_to_image(mlx, filename, &cvs.x, &cvs.y);
	cvs.cvs = mlx_get_data_addr(cvs.img,
			&cvs.pixel_bits, &cvs.line_bytes, &cvs.endian);
	return (cvs);
}
