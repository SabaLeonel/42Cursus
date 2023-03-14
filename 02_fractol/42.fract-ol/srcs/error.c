/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:43:08 by vgroux            #+#    #+#             */
/*   Updated: 2023/01/20 15:47:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_arg(int errcode)
{
	if (errcode == ID_ERROR_WRONG_FRACTAL_NAME)
		ft_printf("%s", ERROR_WRONG_FRACTAL_NAME);
	else if (errcode == ID_ERROR_FLOAT)
		ft_printf("%s", ERROR_FLOAT);
	else if (errcode == ID_ERROR_NBR_ARG)
		ft_printf("%s", ERROR_NBR_ARG);
	else if (errcode == ID_ERROR_WRONG_FRACTAL_NAME_OR_ARG)
		ft_printf("%s", ERROR_WRONG_NAME_ARG);
	ft_printf("\n%s", ERROR_EXEMPLE);
}

int	ft_scandale(t_data *data, char **argv, char *fractal_name)
{
	if (ft_strncmp(fractal_name, "julia", 5))
		return (ID_ERROR_WRONG_FRACTAL_NAME_OR_ARG);
	else if (!ft_strncmp(fractal_name, "julia", 5))
	{
		if (check_double(argv[2]) != -1 && check_double(argv[3]) != -1)
		{
			data->jr = ft_atod(argv[2]);
			data->ar = ft_atod(argv[2]);
			data->ji = ft_atod(argv[3]);
			data->ai = ft_atod(argv[3]);
		}
		else
			return (ID_ERROR_FLOAT);
	}
	return (0);
}

int	ft_check_arg(t_data *data, int argc, char **argv)
{
	char	*fractal_name;

	if (argc != 2 && argc != 4)
		return (ID_ERROR_NBR_ARG);
	fractal_name = ft_strtocase(argv[1], ft_tolower);
	if (argc == 2)
	{
		if (ft_strncmp(fractal_name, "mandelbrot", 10)
			&& ft_strncmp(fractal_name, "burningship", 11))
			return (ID_ERROR_WRONG_FRACTAL_NAME_OR_ARG);
		if (!ft_strncmp(fractal_name, "julia", 5))
			return (ID_ERROR_NBR_ARG);
	}
	else if (argc == 4)
		return (ft_scandale(data, argv, fractal_name));
	return (0);
}

int	check_double(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] && (str[i] != '.' || str[i] != ',') && ft_isdigit(str[i]))
		i++;
	if (str[i] != '.' && str[i] != ',')
		return (-1);
	i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	return (1);
}

int	fractol_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
