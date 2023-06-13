/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/13 15:58:12 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av, t_table *table)
{
	table->data.nb_philo = (int)ft_atoi(av[1]);
	table->data.tt_die = ft_atoi(av[2]);
	table->data.tt_eat = ft_atoi(av[3]);
	table->data.tt_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		table->data.nb_eat = (int)ft_atoi(av[5]);
		if (table->data.nb_eat <= 0)
			return (1);
	}
	if (table->data.tt_die < 1
		|| table->data.tt_die > 2147483647
		|| table->data.tt_eat < 1
		|| table->data.tt_eat > 2147483647
		|| table->data.tt_sleep < 1
		|| table->data.tt_sleep > 2147483647
		|| table->data.nb_philo < 1
		|| table->data.nb_philo > 2147483647)
		return (1);
	return (0);
}

int	is_full(t_state *data)
{
	int					i;

	i = 0;
	while (i < data->nb_philo
		&& access_value_i(&data->philo[i].nb_ate, 0) >= data->nb_eat
		&& data->nb_eat > 0)
		i++;
	if (i == data->nb_philo)
	{
		data->value = 1;
		access_value_i(data->dead, &data->value);
		return (1);
	}
	return (0);
}

int	check_philo(t_state *data)
{
	unsigned long long	curr_time;
	int					i;

	i = -1;
	data->value = 1;
	while (++i < data->nb_philo)
	{
		curr_time = get_time();
		if (access_value_i(&data->philo[i].dead, 0) == 1
			|| curr_time - access_value_l(&data->philo[i].time_lastmeal, 0)
			> data->tt_die)
		{
			print_action(&data->philo[i], DEAD);
			i = -1;
			while (++i < data->nb_philo)
				access_value_i(&data->philo[i].dead, &data->value);
			return (1);
		}
	}
	return (0);
}

int	check_dead(t_state *data)
{
	if (pthread_create(&data->thread_check, NULL,
			&routine_checker, (void *)data) != 0)
	{
		perror("Can't create thread");
		return (1);
	}
	return (0);
}
