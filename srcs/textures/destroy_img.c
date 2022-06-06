/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:48:59 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 18:58:20 by lbisson          ###   ########.fr       */
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
	if (pack->enemy.img)
		mlx_destroy_image(win->mlx, pack->enemy.img);
}	
