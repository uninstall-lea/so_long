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

static void set_up_time(t_time *time)
{
	time->begin = clock();
	time->current = 0;
	time->previous = 0;
}

static void set_up_enemies(t_data *data)
{
	int		i;

	data->enemy = malloc(sizeof(t_enemy) * data->map.nb_enemy);
	if (!data->enemy)
		error_exit(1);
	i = 0;
	while (i < data->map.nb_enemy)
	{
		get_coordinates_enemy(ENEMY, data->map.str_map, &data->enemy[i]);
		data->enemy[i].dir = LEFT;
		i++;
	}
}

static void	move_enemy(char **map, t_enemy *enemy, t_data *data)
{
	if (enemy->dir == LEFT)
	{
		if (decrease_E(map, enemy) == CAN_MOVE)
		{	
			move_ground_on_window_E(enemy, data);
			enemy->x--;
			loose_if_E_walk_on_P(map, enemy, data);
			update_map_for_E('-', map, enemy);
			move_enemy_on_window(enemy, data);
			return ;
		}
		else
			if_obstacle_change_dir(enemy);
	}
	else if (enemy->dir == RIGHT)
	{
		if (increase_E(map, enemy) == CAN_MOVE)
		{
			move_ground_on_window_E(enemy, data);
			enemy->x++;
			loose_if_E_walk_on_P(map, enemy, data);
			update_map_for_E('+', map, enemy);
			move_enemy_on_window(enemy, data);
			return ;
		}
		else
			if_obstacle_change_dir(enemy);
	}
}

static void	patrol(t_enemy *enemy, t_data *data)
{
	int	i;

	i = 0;
	if (has_enough_time_passed(&data->time) == YES)
	{
		while (i < data->map.nb_enemy)
		{
			move_enemy(data->map.str_map, &enemy[i], data);
			i++;
		}
	}
}
int	pat_patrouille(t_data *data)
{
	static int	init = YES;

	if (init == YES)
	{
		set_up_time(&data->time);
		set_up_enemies(data);
		init = NO;
	}
	patrol(data->enemy, data);
	return (BANG_BANG_YOU_SHOT_ME_DOWN);
}
