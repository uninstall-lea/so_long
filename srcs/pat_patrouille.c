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
	time->end = clock();
	time->current = (time->end - time->begin) / CLOCKS_PER_SEC;
	if (time->previous != time->current)
	{
		printf("diff\n");
		time->previous = time->current;
		return (YES);
	}
	return (NO);
}

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

static int increase_E(char **map, t_enemy *enemy)
{
	if (ft_strchr("1CEN", map[enemy->y][enemy->x + 1]) == OBSTACLE)
		return (CANT_MOVE);
	return (CAN_MOVE);
}

static int decrease_E(char **map, t_enemy *enemy)
{
	printf("%c\n", map[enemy->y][enemy->x - 1]);
	if (ft_strchr("1CEN", map[enemy->y][enemy->x - 1]) == OBSTACLE)
		return (CANT_MOVE);
	return (CAN_MOVE);
}

static void if_obstacle_change_dir(t_enemy *enemy)
{
	if (enemy->dir == LEFT)
		enemy->dir = RIGHT;
	else if (enemy->dir == RIGHT)
		enemy->dir = LEFT;
}

static void	move_enemy(t_enemy *enemy, t_data *data)
{
	if (enemy->dir == LEFT)
	{
		printf("jaime largent\n");
		printf("res: %d\n", decrease_E(data->map.str_map, enemy));
		if (decrease_E(data->map.str_map, enemy) == CAN_MOVE)
		{	
			printf("vivement noel\n");
			move_ground_on_window('E', data);
			enemy->x--;
			move_enemy_on_window(data);
		}
		else
			if_obstacle_change_dir(enemy);
	}
	else if (enemy->dir == RIGHT)
	{
		printf("jai mal au burnes\n");
		if (increase_E(data->map.str_map, enemy) == CAN_MOVE)
		{
			printf("bonjour mes cacahuetes");
			move_ground_on_window('E', data);
			enemy->x++;
			move_enemy_on_window(data);
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
		printf("yes\n");
		while (i < data->map.nb_enemy)
		{
			printf("enemy[%d] -> y : %ld / x : %ld\n", i, enemy[i].y, enemy[i].x);
			move_enemy(&enemy[i], data);
			printf("enemy[%d] -> y : %ld / x : %ld\n", i, enemy[i].y, enemy[i].x);
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
