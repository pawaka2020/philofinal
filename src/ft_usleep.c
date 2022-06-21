/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//modification of usleep, allowing it to break the moment a philo dies/finishes
//eating
void	ft_usleep(int sleep, t_philo *philo)
{
	long long	begin;
	long long	current;

	begin = s_to_m();
	while (!philo->dead && philo->eaten < philo->num)
	{
		current = s_to_m();
		if (((current - begin) * 1000) >= (long)sleep)
			break ;
		usleep(100);
	}
}
