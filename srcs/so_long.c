/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:50:33 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 15:56:17 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	init_all_data(int ac, char **av, t_data *data)
{
	init_map(ac, av, &data->map);
	open_window(&data->win, &data->map);
	display_img(data->map.str_map, &data->win, &data->pack);
	get_coordinates_player(PLAYER, data->map.str_map, &data->player);
}

void	init_all_hook(t_data *data)
{
	mlx_key_hook(data->win.win_ptr, hook_events, data);
	mlx_hook(data->win.win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_loop_hook(data->win.mlx, pat_patrouille, data);
}

int	main(int ac, char **av)
{
	t_data		data;

	init_all_data(ac, av, &data);
	init_all_hook(&data);
	mlx_loop(data.win.mlx);
	return (0);
}
