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
		i++;
	}
}

static int	can_enemies_move(t_time *time)
{
	time->current = (time->end - time->begin) / CLOCKS_PER_SEC;
	if (time->previous != time->current)
	{
		time->previous = time->current;
		return (YES);
	}
	return (NO);
}

void	pat_patrouille(t_enemy *enemy, t_data *data)
{
	int	i;

	i = 0;
	while (enemy[i])
	{
		while (increase_E(data->map->str_map, enemy[i], data == CAN_MOVE))
			++enemy[i].x;
	}
}

void	enemies_patrol(t_data *data)
{
	static int	init = YES; 
	t_time	time;
	t_enemy *enemy;

	if (init == YES)
	{
		set_up_time(&time);
		set_up_enemies(enemy, data);
		init = NO;
	}
	if (can_enemies_move == YES)
		pat_patrouille(enemy, data);
}
