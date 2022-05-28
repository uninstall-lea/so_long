#include "../../incs/so_long.h"

void    destroy_img(t_window *win, t_textures *pack)
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
    if (pack->enemies.img)
        mlx_destroy_image(win->mlx, pack->enemies.img);
}