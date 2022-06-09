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

#include "../incs/so_long.h"

static int	has_enough_time_passed(t_time *time)
{
	time->current = (time->end - time->begin) / CLOCKS_PER_SEC;
	if (time->previous != time->current)
	{
		time->previous = time->current;
		return (YES);
	}
	return (NO);
}

static void set_up_time(t_time *time)
{
	time->begin = clock();
	time->end = clock();
	time->current = 0;
	time->previous = 0;
}

static void set_up_enemies(t_enemy *enemy, t_data *data)
{
	int		i;

	enemy = malloc(sizeof(t_enemy) * data->map.nb_enemy);
	if (!enemy)
		error_exit(1);
	i = 0;
	while (i < data->map.nb_enemy)
	{
		get_coordinates_enemy(ENEMY, data->map.str_map, &enemy[i]);
		enemy[i].dir = LEFT;
		i++;
	}
}

static void	move_enemy(t_enemy *enemy, t_data *data)
{
	
	move_ground_on_window(data);
	if (enemy->dir == LEFT)
		enemy->x++;
	else if (enemy->dir == RIGHT)
		enemy->x--;
	move_enemy_on_window(data);	
}

static void	patrol(char **map, t_enemy *enemy, t_data *data)
{
	int	i;

	i = 0;
	if (has_enough_time_passed(&data->time) == YES)
	{
		while (!ft_strchr("1CEN", map[enemy->y][enemy->x]))
			move_enemy(enemy, data);
		if (ft_strchr("1CEN", map[enemy->y][enemy->x]))
		{
			if (enemy[i].dir == LEFT)
				enemy[i].dir = RIGHT;
			else if (enemy[i].dir == RIGHT)
				enemy[i].dir = LEFT;
		}
	}
}

int	pat_patrouille(t_data *data)
{
	static int	init = YES; 

	if (init == YES)
	{
		set_up_time(&data->time);
		set_up_enemies(&data->enemy, data);
		init = NO;
	}
	patrol(data->map.str_map, &data->enemy, data);
	return (BANG_BANG_THEY_SHOT_ME_DOWN);
}
