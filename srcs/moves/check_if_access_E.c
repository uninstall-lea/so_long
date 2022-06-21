/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_access_E.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:36:09 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/21 15:37:45 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	has_enough_time_passed(t_time *time)
{
	time->end = clock();
	time->current = (time->end - time->begin) / (CLOCKS_PER_SEC / 2);
	if (time->previous != time->current)
	{
		time->previous = time->current;
		return (YES);
	}
	return (NO);
}

void if_obstacle_change_dir(t_enemy *enemy)
{
	if (enemy->dir == LEFT)
		enemy->dir = RIGHT;
	else if (enemy->dir == RIGHT)
		enemy->dir = LEFT;
}

int increase_E(char **map, t_enemy *enemy)
{
	if (ft_strchr(OBSTACLE, map[enemy->y][enemy->x + 1]))
		return (CANT_MOVE);
	return (CAN_MOVE);
}

int decrease_E(char **map, t_enemy *enemy)
{
	if (ft_strchr(OBSTACLE, map[enemy->y][enemy->x - 1]))
		return (CANT_MOVE);
	return (CAN_MOVE);
}