/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:25 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/24 17:58:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *msg)
{
	printf("Philo: Error: %s\n", msg);
	exit(1);
}

void	print_action(t_philo *philo, enum e_philo action)
{
	unsigned long long	current_t;
	char				*msg;
	t_state				*data;

	if (philo->dead || safecheck(philo->data->mutex_all_dead, philo->data->all_dead))
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
	pthread_mutex_lock(&philo->data->mutex_print);
	data = philo->data;
	current_t = get_time() - data->start_time;
	printf("%llu\t\t%d %s\n", current_t, philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex_print);
}
