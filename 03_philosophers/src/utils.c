/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:29:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/05/23 18:20:51 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i ++;
	}
	return (res * signe);
}

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_wait(unsigned long long time, t_philo philo)
{
	unsigned long long	current_t;

	current_t = get_time();
	while (!philo.dead)
	{
		usleep(50);
		if (get_time() - current_t >= time)
			break; 
	}
}