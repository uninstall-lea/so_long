/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_access_P.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:50:02 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 16:03:31 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	can_i_go_to_poney(char **map, t_player *player, t_data *data)
{
	if (map[player->y][player->x] == EXIT
		&& data->map.nb_collec <= NO_MORE_COLLECTIBLE_LEFT)
	{
		move_player_on_window(data);
		close_window(data);
	}
	return (NO);
}

static void	if_collec(char *c, t_data *data)
{
		*c = '0';
		data->map.nb_collec--;
}

static int	check_if_access_p(char c, t_data *data)
{
	if (c == BORDER
		|| (c == EXIT && data->map.nb_collec > 0))
		return (CANT_MOVE);
	if (c == COLLEC)
		if_collec(&c, data);
	return (CAN_MOVE);
}

int	can_i_decrease_p(char where, char **map, t_player *player, t_data *data)
{
	if (where == 'y')
		return (check_if_access_p(map[player->y - 1][player->x], data));
	else if (where == 'x')
		return (check_if_access_p(map[player->y][player->x - 1], data));
	return (CANT_MOVE);
}

int	can_i_increase_p(char where, char **map, t_player *player, t_data *data)
{
	if (where == 'y')
		return (check_if_access_p(map[player->y + 1][player->x], data));
	else if (where == 'x')
		return (check_if_access_p(map[player->y][player->x + 1], data));
	return (CANT_MOVE);
}
