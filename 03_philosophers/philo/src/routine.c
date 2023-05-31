/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:18:01 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/31 18:38:32 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	isdead(philo);
	philo->time_lastmeal = get_time();
	print_action(philo, FORK);
	print_action(philo, FORK);
	print_action(philo, EAT);
	philo->nb_ate += 1;
	if (philo->nb_ate == philo->data.nb_eat)
		is_full(philo);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_r);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(philo->data.tt_eat / 10);
	while (1)
	{
		if (isdead(philo))
			break ;
		print_action(philo, THINK);
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->fork_r);
		eat(&philo[i]);
		ft_usleep(philo->data.tt_eat);
		print_action(philo, SLEEP);
		ft_usleep(philo->data.tt_sleep);
		if (isdead(philo))
			break ;
	}
	return (0);
}
