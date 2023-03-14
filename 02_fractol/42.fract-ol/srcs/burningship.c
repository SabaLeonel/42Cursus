/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:06:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 14:25:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++y < HEIGHT)
	{
		data->ci = -(data->y_max - ((y + data->y_off)
					* ((data->y_max - data->y_min) / (WIDTH - 1))));
		while (++x < WIDTH)
		{
			data->cr = (data->x_min + ((x + data->x_off)
						* ((data->x_max - data->x_min) / (HEIGHT - 1))));
			burning_calc(data, x, y);
		}
		x = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	burning_calc(t_data *data, int x, int y)
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
		zr2 = pow(fabs(zr), 2);
		zi2 = pow(fabs(zi), 2);
		if (zr2 + zi > 4)
			break ;
		zi = 2. * fabs(zr) * fabs(zi) + data->ci;
		zr = zr2 - zi2 + data->cr;
		data->iter += 1;
	}
	if (data->iter == MAX_I)
		color = COLOR_MAX_I;
	else
		color = choose_color(data->iter, zr2, zi2, data);
	put_pixel(data, x, y, color);
}
