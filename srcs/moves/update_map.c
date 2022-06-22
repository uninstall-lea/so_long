/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:51:22 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 15:51:25 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	update_map_for_player(char where, char how, char **map, t_player *p)
{
	if (where == 'y' && how == '-')
	{
		map[p->y][p->x] = 'P';
		map[p->y + 1][p->x] = '0';
	}
	else if (where == 'x' && how == '-')
	{
		map[p->y][p->x] = 'P';
		map[p->y][p->x + 1] = '0';
	}
	else if (where == 'y' && how == '+')
	{
		map[p->y][p->x] = 'P';
		map[p->y - 1][p->x] = '0';
	}
	else if (where == 'x' && how == '+')
	{
		map[p->y][p->x] = 'P';
		map[p->y][p->x - 1] = '0';
	}
}

void	update_map_for_enemy(char how, char **map, t_enemy *e)
{
	if (how == '-')
	{
		map[e->y][e->x] = 'N';
		map[e->y][e->x + 1] = '0';
	}
	if (how == '+')
	{
		map[e->y][e->x] = 'N';
		map[e->y][e->x - 1] = '0';
	}
}
