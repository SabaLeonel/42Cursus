/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/24 20:15:37 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av, t_state *data)
{
	data->nb_philo = (int)ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->max_meal = (int)ft_atoi(av[5]);
		if (data->max_meal <= 0)
			return (-1);
	}
	if (data->tt_die < 1
		|| data->tt_die > 2147483647
		|| data->tt_eat < 1
		|| data->tt_eat > 2147483647
		|| data->tt_sleep < 1
		|| data->tt_sleep > 2147483647
		|| data->nb_philo < 1
		|| data->nb_philo > 2147483647)
		return (-1);
	return (0);
}

/*
** 		check si meurt (diff entre timestamp actuel et timelastmeal > ttdie || == ttdie MORT
** 		Si meurt lock mutex_print
*/
int	check_state(t_state *data)
{
	int					i;
	unsigned long long	curr_time;

	i = 0;
	while (i < data->nb_philo)
	{
		curr_time = get_time();
		pthread_mutex_lock(&data.)
		if (data->philo[i].dead
			|| curr_time - data->philo[i].time_lastmeal > data->tt_die)
		{
			print_action(&data->philo[i], DEAD);
			data->philo[i].dead = 1;
		}
		if (data->philo[i].dead)
			return (-1);
		i ++;
	}
	return (0);
}

int	check_all_eat(t_state *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo && data->philo[i].nb_ate >= data->max_meal && data->max_meal > 0)
		i ++;
	if (data->nb_philo == i)
	{
		data->all_dead = 1;
		return (-1);
	}
	return (0);
}