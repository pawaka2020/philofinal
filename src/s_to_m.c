/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//captures timestamp using gettimeofday
//also rounds down to remove runoff error.
//working is 20
long	s_to_m(void)
{
	struct timeval	current_time;
	long long		ms;

	gettimeofday(&current_time, 0);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	ms /= 10;
	ms *= 10;
	return (ms);
}