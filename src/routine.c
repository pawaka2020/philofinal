/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//we set for the philos 2, 4, 6, etc to act later than 1, 3, 5.
//but we don't want to make them to wait too much.
//20 is just within the minimum rounding factor of s_to_m
void	*routine(void *arg)
{
	t_info			*info;

	info = (t_info *)arg;
	print_log(info);
	if (odd_num(info->id) == 1)
		ft_usleep(100, info->ptr);
	while (!info->ptr->dead && info->ptr->eaten < info->ptr->num)
	{
		think_to_eat(info);
		eat_to_sleep(info);
	}
	return (0);
}
