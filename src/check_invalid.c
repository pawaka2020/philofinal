/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//makes sure all params are valid before continuing
int	check_invalid(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (1);
	i = 1;
	while (i < 5)
	{
		if ((i > 1) && (ft_atoi(argv[i]) < 60))
			return (1);
		i++;
	}
	if (argv[5] == 0)
		return (0);
	return (0);
}
