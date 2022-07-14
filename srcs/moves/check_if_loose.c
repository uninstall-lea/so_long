/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_loose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:39:37 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 21:21:44 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	loose_if_e_walk_on_p(char **map, t_enemy *e, t_data *data)
{
	if (map[e->y][e->x] == PLAYER)
	{
		bisson_rgb(e, data);
		write(2, "HAHA ! YOU LOST ! MECREANT !\n", 30);
		close_window(data);
	}
}

void	loose_if_p_walk_on_e(char **map, t_player *p, t_data *data)
{
	if (map[p->y][p->x] == ENEMY)
	{
		write(2, "HAHA ! YOU LOST ! MECREANT !\n", 30);
		close_window(data);
	}
}
