/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/06/02 17:37:03 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *msg)
{
	printf("Philo: Error: %s\n", msg);
	return (1);
}



void	print_action(t_philo *philo, enum e_philo action)
{
	unsigned long long	current_t;
	char				*msg;

	if (access_value_i(&philo->dead, 0) || access_value_i(philo->data.dead, 0))
		return ;
	if (action == FORK)
		msg = "has taken a fork";
	if (action == EAT)
		msg = "is eating";
	if (action == SLEEP)
		msg = "is sleeping";
	if (action == THINK)
		msg = "is thinking";
	if (action == DEAD)
		msg = "died";
	if (action == FULL)
		msg = "Philos are full";
	pthread_mutex_lock(philo->data.m_print);
	if (DEAD == action)
		printf("DEAD");
	current_t = get_time() - philo->data.start_time;
	if (action != FULL)
		printf("%llu\t\t%d %s\n", current_t, philo->id, msg);
	else
		printf("%llu\t\t%s\n", current_t, msg);
	pthread_mutex_unlock(philo->data.m_print);
}
