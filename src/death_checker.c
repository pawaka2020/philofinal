/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//this is the process for checking to see if a philo dies.
//a mutex is placed to prevent non-death messages from threads to be posted
//at the same time as this. 
//a slight sleep is included at the end of the loop to minimize errrors.
void	death_checker(t_philo *philo)
{
	int			i;
	long		time;
	long		dead;

	while (!philo->dead)
	{
		i = 0;
		if (philo->eaten == philo->num)
			return ;
		while (!(philo->dead) && (i < philo->num))
		{
			time = s_to_m();
			dead = philo->info[i].death_timer;
			if (time >= dead)
			{
				philo->dead = 1;
				pthread_mutex_lock(&philo->miniphone);
				printf("%ld %d died\n", time, philo->info[i].id + 1);
				pthread_mutex_unlock(&philo->miniphone);
				break ;
			}
			i++;
			ft_usleep(100, philo);
		}
	}
}
