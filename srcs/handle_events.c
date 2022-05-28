#include "../incs/so_long.h"

static t_fptr   dispatch(int keycode)
{
	int				index;
	static int		keybind[10] = {UP, W, Z, LEFT, A, Q, DOWN, S, RIGHT, D};
	static t_fptr	event[10] = {move_up, move_up, move_up, move_left, move_left,
								move_left, move_down, move_down, move_right, move_right};

	index = ft_intchr(keybind, 10, keycode);
	if (index == NOT_FOUND)
		return (NULL);
	return (event[index]);
}

int   handle_events(int keycode, t_data *data)
{
//	int	 *x;
//	int	 *y;
	t_fptr  event;

	event = (*dispatch)(keycode);
	if (event)
		(*event)(data->map.map, data);
	else if (keycode == ESC)
		close_window(data);
	return (0);
}