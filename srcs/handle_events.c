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
	t_fptr  event;
	
	printf("pb1\n");
	event = (*dispatch)(keycode);
	printf("pb2\n");
	if (event)
	{
		printf("pb3\n");
		(*event)(data->map.map, data);
		printf("pb4\n");
	}
	else if (keycode == ESC)
		close_window(data);
	return (0);
}