/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_loose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:39:37 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/21 16:43:27 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	loose_if_E_walk_on_P(char **map, t_enemy *e, t_data *data)
{
	if (map[e->y][e->x] == PLAYER)
	{
		move_enemy_on_window(e, data);
		write(2, "HAHA ! YOU LOST ! MECREANT !\n", 30);
		close_window(data);
	}
}

void	loose_if_P_walk_on_E(char **map, t_player *p, t_data *data)
{
	if (map[p->y][p->x] == ENEMY)
	{
		write(2, "HAHA ! YOU LOST ! MECREANT !\n", 30);
		close_window(data);
	}
}