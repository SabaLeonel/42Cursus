/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:53:11 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 14:52:19 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_f(t_data *data, double zoom)
{
	data->x_max *= zoom;
	data->x_min *= zoom;
	data->y_min *= zoom;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
}

void	move_f(t_data *data, int x, int y)
{
	data->x_off += x;
	data->y_off -= y;
}

void	change_input(t_data *data, double up)
{
	data->jr += up;
	data->ji += up;
}

void	reset(t_data *data)
{
	data->x_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
	data->x_off = 0;
	data->y_off = 0;
	data->jr = data->ar;
	data->ji = data->ai;
}

void	param_color(t_data *data, int keycode)
{
	data->color_r = 0;
	data->color_g = 0;
	data->color_b = 0;
	if (keycode == RED || keycode == PURPLE || keycode == YELLOW)
		data->color_r = 1;
	if (keycode == GREEN || keycode == CYAN || keycode == YELLOW)
		data->color_g = 1;
	if (keycode == BLUE || keycode == PURPLE || keycode == CYAN)
		data->color_b = 1;
}
