/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:06 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/29 21:43:54 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "mlx.h"
# include "hook.h"

typedef struct s_canvas
{
	void		*img;
	char		*cvs;
	int			x;
	int			y;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}	t_canvas;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	t_canvas	cvs;
}	t_window;

typedef	struct s_anim
{
	t_canvas	frames[5];
	int			current_frame;
	int			frame_amount;
	int			time_to_change;
	int			timer;
}	t_anim;


typedef struct s_game
{
	int			**map;
	t_vector	player_pos;
	t_window	window;
	t_vector	size;
	int			collectible;
	int			coll_count;
	int			players;
	int			exit;
	int			move_count;
	t_anim	 	sprites[5];
	char		keys[200];
}	t_game;

enum
{
	EMPTY,
	WALL,
	PLAYER,
	COLLECTIBLE,
	EXIT,
};

void		error(char *message);
t_canvas	ft_init_image(void *mlx, char *filename);
t_vector	map_size(char *path);
int			check_elements(char c, t_game *game);
void		check_extension(char *path);
void		generate_map(t_game *game, int fd, char *temp);
void		check_min_amount(t_game *game);
void		check_wall(t_game *game);
void		init_sprites(t_game *game);
void		check_is_solvable(int x, int y, t_game *game);
void		clean_solvable(t_game *game);
void		parse_map(char *path, t_game *game);
void		draw_map(t_game *game);
int			key_hook(t_game *game);
int			hook_move(t_vector new_pos, t_game *game);
// void		printmap(t_game *game);

#endif