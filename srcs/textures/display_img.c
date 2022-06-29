/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:50:53 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/29 16:25:45 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	convert_all_xpm(char **map, t_window *win, t_textures *set)
{
	set->exit.img = mlx_xpm_file_to_image(win->mlx, set->exit.path,
			&set->exit.w, &set->exit.h);
	set->ground.img = mlx_xpm_file_to_image(win->mlx, set->ground.path,
			&set->ground.w, &set->ground.h);
	set->border.img = mlx_xpm_file_to_image(win->mlx, set->border.path,
			&set->border.w, &set->border.h);
	set->collec.img = mlx_xpm_file_to_image(win->mlx, set->collec.path,
			&set->collec.w, &set->collec.h);
	set->player.img = mlx_xpm_file_to_image(win->mlx, set->player.path,
			&set->player.w, &set->player.h);
	set->red_enemy.img = mlx_xpm_file_to_image(win->mlx, set->red_enemy.path,
			&set->red_enemy.w, &set->red_enemy.h);
	set->blue_enemy.img = mlx_xpm_file_to_image(win->mlx, set->blue_enemy.path,
			&set->blue_enemy.w, &set->blue_enemy.h);
	set->green_enemy.img = mlx_xpm_file_to_image(win->mlx, set->green_enemy.path,
			&set->green_enemy.w, &set->green_enemy.h);
	if (!set->collec.img || !set->player.img ||!set->exit.img
		|| !set->ground.img || !set->border.img || !set->red_enemy.img
		|| !set->green_enemy.img || !set->blue_enemy.img)
	{
		ft_free(map);
		destroy_img(win, set);
		error_exit(6);
	}
}

static void	set_textures(char **map, t_window *win, t_textures *set)
{	
	set->collec.path = "./srcs/textures/doll.xpm";
	set->ground.path = "./srcs/textures/rainbow.xpm";
	set->exit.path = "./srcs/textures/rainbow_dash.xpm";
	set->border.path = "./srcs/textures/malicious_star.xpm";
	set->player.path = "./srcs/textures/lbisson_de_noel.xpm";
	set->red_enemy.path = "./srcs/textures/red_bisson.xpm";
	set->green_enemy.path = "./srcs/textures/green_bisson.xpm";
	set->blue_enemy.path = "./srcs/textures/blue_bisson.xpm";
	convert_all_xpm(map, win, set);
}

void	display_img(char **map, t_window *win, t_textures *set)
{
	int	x;
	int	y;

	y = -1;
	set_textures(map, win, set);
	while (++y * IMG_SIZE < win->h)
	{
		x = -1;
		while (++x * IMG_SIZE < win->w)
		{
			if (map[y][x] == EXIT)
				put_img_to_window(x, y, win, set->exit);
			else if (map[y][x] == GROUND)
				put_img_to_window(x, y, win, set->ground);
			else if (map[y][x] == BORDER)
				put_img_to_window(x, y, win, set->border);
			else if (map[y][x] == COLLEC)
				put_img_to_window(x, y, win, set->collec);
			else if (map[y][x] == PLAYER)
				put_img_to_window(x, y, win, set->player);
			else if (map[y][x] == ENEMY)
				put_img_to_window(x, y, win, set->red_enemy);
		}
	}
}
