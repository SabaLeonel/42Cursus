/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/02 17:34:16 by lsaba-qu         ###   ########.fr       */
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

int	is_full(t_philo *philo)
{
	unsigned long long	curr_time;
	int					i;

	i = -1;
	// while (i < philo->data.philo
	// 	&& access_value_i(&philo[i].))
	curr_time = get_time();
	pthread_mutex_lock(philo->data.m_eat);
	if (++(*philo->data.full_philo) == philo->data.nb_eat)
	{
		pthread_mutex_lock(philo->data.m_print);
		printf("%llu\t\tPhilos are full\n", curr_time - philo->data.start_time);
		pthread_mutex_unlock(philo->data.m_print);
		print_action(philo, FULL);
		return (1);
	}
	pthread_mutex_unlock(philo->data.m_eat);
	return (0);
}

int	check_philo(t_state *data)
{
	unsigned long long	curr_time;
	int					i;

	i = -1;
	while (++i < data->nb_philo)
	{
		curr_time = get_time();
		if (curr_time - access_value_l(&data->philo[i].time_lastmeal, 0)
			> data->tt_die)
		{
			data->value = 1;
			access_value_i(data->dead, &data->value);
			pthread_mutex_lock(data->m_print);
			printf("%llu\t\t%d died\n", curr_time - data->philo[i].time_lastmeal,
				data->philo[i].id);
			pthread_mutex_unlock(data->m_print);
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
			&routine_checker, (void *)data))
		return (1);
	return (0);
}
