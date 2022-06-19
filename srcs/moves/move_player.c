/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/07 18:17:06 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (decrease_P('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window('P', data);
		data->player.y--;
		can_i_go_to_poney(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_left(char **map, t_data *data)
{
	if (decrease_P('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window('P', data);
		data->player.x--;
		can_i_go_to_poney(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_down(char **map, t_data *data)
{
	if (increase_P('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window('P', data);
		data->player.y++;
		can_i_go_to_poney(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_right(char **map, t_data *data)
{
	if (increase_P('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window('P', data);
		data->player.x++;
		can_i_go_to_poney(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}
