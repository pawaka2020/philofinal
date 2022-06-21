/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//checks for even number
int	even_num(int num)
{
	if (num == 0)
		return (1);
	if (num % 2 == 0)
		return (1);
	return (0);
}
