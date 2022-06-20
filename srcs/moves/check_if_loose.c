/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_loose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:39:37 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/20 17:46:49 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	check_if_loose_E(char **map, t_enemy *enemy, t_data *data)
{
	if (ft_strchr("P", map[enemy->y][enemy->x]))
	{
		move_enemy_on_window(enemy, data);
		write(2, "HAHA ! YOU LOST !\n", 19);
		close_window(data);
	}
}

void	check_if_loose_P(char **map, t_player *player, t_data *data)
{
	if (ft_strchr("E", map[player->y][player->x]))
	{
		write(2, "HAHA ! YOU LOST !\n", 19);
		close_window(data);
	}
}