/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:45:15 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 15:47:10 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	get_coordinates_player(char to_find, char **map, t_player *to_init)
{
	to_init->y = 0;
	to_init->x = 0;
	to_init->nb_moves = 0;
	while (map[to_init->y])
	{
		to_init->x = ft_strchr(map[to_init->y], to_find) - map[to_init->y];
		if (to_init->x >= 1)
			return ;
		to_init->y++;
	}
}

void	get_coordinates_enemy(char to_find, char **map, t_enemy *to_init)
{
	int			i;
	static int	nb_enemy = 0;

	i = 0;
	nb_enemy++;
	to_init->y = 0;
	to_init->x = 0;
	while (map[to_init->y])
	{
		to_init->x = ft_strchr(map[to_init->y] + to_init->x, to_find)
			- map[to_init->y];
		if (to_init->x >= 1)
		{
			i++;
			if (i == nb_enemy)
				return ;
			to_init->x++;
		}
		else
		{
			to_init->y++;
			to_init->x = 0;
		}
	}
}
