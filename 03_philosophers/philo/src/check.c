/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:41 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/29 15:10:01 by lsaba-qu         ###   ########.fr       */
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

int	isdead(t_philo *philo)
{
	unsigned long long	curr_time;

	curr_time = get_time();
	if (curr_time - philo->time_lastmeal > philo->data.tt_die)
	{
		pthread_mutex_lock(philo->data.m_print);
		pthread_mutex_lock(philo->data.m_nb_eat);
		pthread_mutex_lock(philo->data.m_dead);
		philo->dead = 1;
		printf("%llu\t\tPhilo %d is dead\n",
			curr_time - philo->data.start_time, philo->id);
		return (1);
	}
	return (0);
}

int	is_full(t_philo *philo)
{
	unsigned long long	curr_time;

	curr_time = get_time();
	pthread_mutex_lock(philo->data.m_nb_eat);
	if (++(*philo->data.full_philo) == philo->data.nb_eat)
	{
		pthread_mutex_lock(philo->data.m_print);
		printf("%llu\t\tphilos are full\n", curr_time - philo->data.start_time);
		return (1);
	}
	pthread_mutex_unlock(philo->data.m_nb_eat);
	return (0);
}
