/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:50:33 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 21:31:21 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	init_all_data(int ac, char **av, t_data *data)
{
	data->enemy = NULL;
	init_map(ac, av, data);
	open_window(&data->win, &data->map);
	get_coordinates_player(data->map.str_map, &data->player);
	display_img(data->map.str_map, &data->win, &data->pack, data);
}

void	init_all_hook(t_data *data)
{
	mlx_key_hook(data->win.win_ptr, hook_events, data);
	mlx_hook(data->win.win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_loop_hook(data->win.mlx, pat_patrol, data);
}

int	main(int ac, char **av)
{
	t_data		data;

	init_all_data(ac, av, &data);
	init_all_hook(&data);
	mlx_loop(data.win.mlx);
	return (0);
}
