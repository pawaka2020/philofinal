/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_log(t_info *info)
{
	pthread_mutex_lock(&info->ptr->miniphone);
	if (!info->ptr->dead && info->ptr->eaten < info->ptr->num)
	{
		if (info->state == forking)
			printf("%ld %d has taken a fork\n", s_to_m(), info->id + 1);
		if (info->state == thinking)
			printf("%ld %d is thinking\n", s_to_m(), info->id + 1);
		if (info->state == sleeping)
			printf("%ld %d is sleeping\n", s_to_m(), info->id + 1);
		if (info->state == eating)
			printf("%ld %d is eating\n", s_to_m(), info->id + 1);
	}
	pthread_mutex_unlock(&info->ptr->miniphone);
}
