/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:47:24 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 18:55:06 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	increase_enemy(char **map, t_enemy *enemy, t_data *data)
{
	put_img_to_window(enemy->x, enemy->y, &data->win, data->pack.ground);
	enemy->x--;
	loose_if_e_walk_on_p(map, enemy, data);
	update_map_for_enemy('-', map, enemy);
	bisson_rgb(enemy, data);
}

static void	decrease_enemy(char **map, t_enemy *enemy, t_data *data)
{
	put_img_to_window(enemy->x, enemy->y, &data->win, data->pack.ground);
	enemy->x++;
	loose_if_e_walk_on_p(map, enemy, data);
	update_map_for_enemy('+', map, enemy);
	bisson_rgb(enemy, data);
}

static void	move_enemy(char **map, t_enemy *enemy, t_data *data)
{
	if (enemy->dir == LEFT)
	{
		if (can_i_decrease_e(map, enemy) == CAN_MOVE)
		{	
			increase_enemy(map, enemy, data);
			return ;
		}
		else
			if_obstacle_change_dir(enemy);
	}
	else if (enemy->dir == RIGHT)
	{
		if (can_i_increase_e(map, enemy) == CAN_MOVE)
		{
			decrease_enemy(map, enemy, data);
			return ;
		}
		else
			if_obstacle_change_dir(enemy);
	}
}

int	pat_patrouille(t_data *data)
{
	int			i;
	static int	init = YES;

	if (init == YES)
	{
		set_up_time(&data->time);
		set_up_enemies(data);
		init = NO;
	}
	i = 0;
	if (has_enough_time_passed(&data->time) == YES)
	{
		while (i < data->map.nb_enemy)
		{
			move_enemy(data->map.str_map, &data->enemy[i], data);
			i++;
		}
	}
	return (BANG_BANG_YOU_SHOT_ME_DOWN);
}
