/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:51 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 20:41:32 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static t_fptr	dispatch(int keycode)
{
	int				index;
	static int		keybind[10] = {UP, W, Z, LEFT, A, Q, DOWN, S, RIGHT, D};
	static t_fptr	event[10] = {move_up, move_up, move_up, move_left,
		move_left, move_left, move_down, move_down, move_right, move_right};

	index = find_index(keybind, 10, keycode);
	if (index == NOT_FOUND)
		return (NULL);
	return (event[index]);
}

int	hook_events(int keycode, t_data *data)
{
	t_fptr	event;

	event = (*dispatch)(keycode);
	if (event)
		(*event)(data->map.str_map, &data->player, data);
	else if (keycode == ESC)
		close_window(data);
	return (0);
}
