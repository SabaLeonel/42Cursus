/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:18:01 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/23 18:20:22 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo philo)
{
	pthread_mutex_lock(&philo.data->fork[philo.fork_left_id]);
	pthread_mutex_lock(&philo.data->fork[philo.fork_right_id]);
	print_action(&philo, FORK);
	philo.time_lastmeal = get_time();
	print_action(&philo, EAT);
	philo.nb_ate += 1;
	ft_wait(philo.data->tt_eat, philo);
	pthread_mutex_unlock(&philo.data->fork[philo.fork_left_id]);
	pthread_mutex_unlock(&philo.data->fork[philo.fork_right_id]);
	
}
