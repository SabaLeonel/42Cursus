/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:26:19 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 14:26:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < HEIGHT)
	{
		data->ci = (data->y_max - ((y + data->y_off)
					* ((data->y_max - data->y_min) / (WIDTH - 1))));
		while (++x < WIDTH)
		{
			data->cr = (data->x_min + ((x + data->x_off)
						* ((data->x_max - data->x_min) / (HEIGHT - 1))));
			mandel_calc(data, x, y);
		}
		x = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	mandel_calc(t_data *data, int x, int y)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		color;

	data->iter = 0;
	zr = data->cr;
	zi = data->ci;
	while (data->iter < MAX_I)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4)
			break ;
		zi = 2 * zr * zi + data->ci;
		zr = zr2 - zi2 + data->cr;
		data->iter += 1;
	}
	if (data->iter == MAX_I)
		color = COLOR_MAX_I;
	else
		color = choose_color(data->iter, zr2, zi2, data);
	put_pixel(data, x, y, color);
}
