/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:48:59 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/29 17:01:03 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	destroy_img(t_window *win, t_textures *pack)
{
	if (pack->exit.img)
		mlx_destroy_image(win->mlx, pack->exit.img);
	if (pack->ground.img)
		mlx_destroy_image(win->mlx, pack->ground.img);
	if (pack->border.img)
		mlx_destroy_image(win->mlx, pack->border.img);
	if (pack->collec.img)
		mlx_destroy_image(win->mlx, pack->collec.img);
	if (pack->player.img)
		mlx_destroy_image(win->mlx, pack->player.img);
	if (pack->red_enemy.img)
		mlx_destroy_image(win->mlx, pack->red_enemy.img);
	if (pack->green_enemy.img)
		mlx_destroy_image(win->mlx, pack->green_enemy.img);
	if (pack->blue_enemy.img)
		mlx_destroy_image(win->mlx, pack->blue_enemy.img);
}	
