/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:54:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 16:49:32 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		x;
	int		y;
	int		iter;
	int		color_r;
	int		color_g;
	int		color_b;
	double	x_off;
	double	y_off;
	double	jr;
	double	ji;
	double	ar;
	double	ai;
	double	cr;
	double	ci;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_data;

int		main(int argc, char **argv);
void	mlx_start(t_data *data);
int		fractal_render(t_data *data);
void	mandelbrot(t_data *data);
void	mandel_calc(t_data *data, int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);
void	update_f(t_data *data, double zoom);
void	move_f(t_data *data, int x, int y);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_data *data);
void	ft_error_arg(int errcode);
int		ft_check_arg(t_data *data, int argc, char **argv);
void	julia_calc(t_data *data, int x, int y);
void	julia(t_data *data);
int		choose_fractal(char *name);
int		fractol_exit(t_data *data);
int		check_double(char *str);
int		color_multi(double iter);
void	update_f(t_data *data, double zoom);
void	move_f(t_data *data, int x, int y);
void	change_input(t_data *data, double up);
void	reset(t_data *data);
int		encode_rgb(t_data *data, double ratio);
int		choose_color(int iter, double zr2, double zi2, t_data *data);
void	burningship(t_data *data);
void	burning_calc(t_data *data, int x, int y);
void	param_color(t_data *data, int keycode);
int		ft_scandale(t_data *data, char **argv, char *fractal_name);

#endif