/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:18:01 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/25 19:57:45 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->fork_r);
	philo->time_lastmeal = get_time();
	print_action(philo, FORK);
	print_action(philo, FORK);
	print_action(philo, EAT);
	philo->nb_ate += 1;
	if (philo->nb_ate == philo->data.nb_eat)
		are_full(philo);
	ft_usleep(philo->data.tt_eat);
	pthread_mutex_unlock(&philo->fork_r);
	pthread_mutex_unlock(&philo->fork_r);
}

void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	table->data = philo->data;
	if (philo->id % 2)
		usleep(philo->data.tt_eat / 10);
	while (!philo->dead)
	{
		isdead(philo);
		eat(&philo[i]);
		ft_usleep(table->data.tt_eat);
		isdead(philo);
		print_action(&table->data.philo[i], SLEEP);
		ft_usleep(table->data.tt_sleep);
		isdead(philo);
		print_action(&table->data.philo[i], THINK);
	}
	return (0);
}
