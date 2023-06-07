/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:18:01 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/06 19:46:48 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	unsigned long long int	l;
	int						i;

	pthread_mutex_lock(&philo->fork);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->fork_r);
	print_action(philo, FORK);
	print_action(philo, EAT);
	ft_usleep(philo->data.tt_eat, philo);
	i = access_value_i(&philo->nb_ate, 0) + 1;
	access_value_i(&philo->nb_ate, &i);
	l = get_time();
	access_value_l(&philo->time_lastmeal, &l);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->fork_r);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_create(&philo->data.thread_check, NULL, &routine_checker, (void *)&philo->data))
		perror("Error creating thread");
	if (philo->id % 2)
		usleep(philo->data.tt_eat / 10);
	while (!access_value_i(&philo->dead, NULL))
	{
		print_action(philo, THINK);
		eat(philo);
		if (access_value_i(philo->data.dead, NULL) == 1)
			break ;
		print_action(philo, SLEEP);
		ft_usleep(philo->data.tt_sleep, philo);
	}
	if (pthread_join(philo->data.thread_check, NULL))
		perror("Error joining thread");
	return (0);
}

void	*routine_checker(void *data)
{
	t_state	*philodata;

	philodata = (t_state *)data;
	philodata->value = 1;
	while (!access_value_i(philodata->dead, 0))
	{
		if (check_philo(data))
			break ;
		 // if (is_full(data))
	}
	// printf("BREAK");
	access_value_i(philodata->dead, &philodata->value);
	return (NULL);
}
