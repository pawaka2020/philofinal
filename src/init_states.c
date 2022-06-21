/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time(void)
{
	struct timeval	current_time;
	long long		ms;
	int				factor;

	gettimeofday(&current_time, 0);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (ms);
}

t_philo	*init_states(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		pthread_mutex_init(&philo->fork[i], 0);
		philo->info[i].id = i;
		philo->info[i].state = thinking;
		philo->info[i].ptr = philo;
		philo->info[i].times_eat = 0;
		philo->info[i].death_timer = s_to_m() + philo->death_time;
		i++;
	}
	philo->dead = 0;
	return (philo);
}
