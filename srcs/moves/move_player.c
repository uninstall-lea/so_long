/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 18:22:29 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (decrease('y', map, data) == CAN_MOVE)
	{
		move_ground_on_window(data);
		data->player.y--;
		check_for_collec(map, data);
		check_for_exit(map, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_left(char **map, t_data *data)
{
	if (decrease('x', map, data) == CAN_MOVE)
	{
		move_ground_on_window(data);
		data->player.x--;
		check_for_collec(map, data);
		check_for_exit(map, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_down(char **map, t_data *data)
{
	if (increase('y', map, data) == CAN_MOVE)
	{
		move_ground_on_window(data);
		data->player.y++;
		check_for_collec(map, data);
		check_for_exit(map, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_right(char **map, t_data *data)
{
	if (increase('x', map, data) == CAN_MOVE)
	{
		move_ground_on_window(data);
		data->player.x++;
		check_for_collec(map, data);
		check_for_exit(map, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}
