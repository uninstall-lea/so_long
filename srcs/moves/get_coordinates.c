/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:45:15 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/29 18:13:30 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	get_coordinates_player(char **map, t_player *to_init)
{
	to_init->y = 1;
	to_init->x = 1;
	to_init->nb_moves = 0;
	while (map[to_init->y])
	{
		while (map[to_init->y][to_init->x])
		{
			if (map[to_init->y][to_init->x] == PLAYER)
				return ;
			to_init->x++;
		}
		to_init->y++;
		to_init->x = 1;
	}
}

void	get_coordinates_enemy(char **map, t_enemy *to_init)
{
	int			i;
	static int	nb_enemy = 0;

	i = 0;
	nb_enemy++;
	to_init->y = 1;
	while (map[to_init->y])
	{
		to_init->x = 1;
		while (map[to_init->y][to_init->x])
		{
			if (map[to_init->y][to_init->x] == ENEMY)
			{
				i++;
				if (i == nb_enemy)
					return ;
			}
			to_init->x++;
		}
		to_init->y++;
	}
}
