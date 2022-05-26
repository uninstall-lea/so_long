#include "../incs/so_long.h"

t_fptr   dispatch(char keycode)
{
    int     index;
    t_fptr  event[5];

    event[0] = close_window;
    event[1] = move_up;
    event[2] = move_left;
    event[3] = move_right;
    event[4] = move_down;
    event = ft_strchr(EVENT)
    
}

void    event()
{
    t_fptr event;

    mlx_key_hook(win->win_ptr, , win);