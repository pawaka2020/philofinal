/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_to_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//covers the phase from eating to sleeping
void	eat_to_sleep(t_info *info)
{
	if (info->state == eating)
	{
		pthread_mutex_unlock(&info->ptr->fork[info->id]);
		pthread_mutex_unlock(&info->ptr->fork[(info->id + 1) % info->ptr->num]);
		if (!info->ptr->dead)
			info->state = sleeping;
		print_log(info);
		ft_usleep(info->ptr->sleep_time, info->ptr);
		info->left = 0;
		info->right = 0;
		if (!info->ptr->dead)
			info->state = thinking;
		print_log(info);
	}
}
