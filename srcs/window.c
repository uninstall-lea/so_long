/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:50:51 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 21:23:15 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	close_window(t_data *data)
{
	destroy_img(&data->win, &data->pack);
	mlx_destroy_window(data->win.mlx, data->win.win_ptr);
	mlx_destroy_display(data->win.mlx);
	ft_free(data->map.str_map);
	free(data->win.mlx);
	free(data->enemy);
	exit(EXIT_SUCCESS);
}

void	open_window(t_window *win, t_map *map)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		error_exit(1);
	win->h = map->nb_lines * IMG_SIZE;
	win->w = map->nb_columns * IMG_SIZE;
	win->win_ptr = mlx_new_window(win->mlx, win->w, win->h,
			"Run away from evil_fat_bisson RGB editon");
}

void	put_img_to_window(int x, int y, t_window *win, t_image to_put)
{
	mlx_put_image_to_window(win->mlx, win->win_ptr, to_put.img,
		x * IMG_SIZE, y * IMG_SIZE);
}
