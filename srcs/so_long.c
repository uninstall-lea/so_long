/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:50:33 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/09 17:43:13 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	t_data		data;

	init_map(ac, av, &data.map);
	open_window(&data.win, &data.map);
	display_img(data.map.str_map, &data.win, &data.pack);
	get_coordinates_player(PLAYER, data.map.str_map, &data.player);
	mlx_key_hook(data.win.win_ptr, hook_events, &data);
	mlx_hook(data.win.win_ptr, ON_DESTROY, 0, close_window, &data);
	mlx_loop_hook(data.win.mlx, pat_patrouille, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
