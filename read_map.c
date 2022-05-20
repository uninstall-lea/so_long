#include "so_long.h"

static void	check_map_elems(int line, int last_line, char *map)
{
	int	i;
	int	n_exit;
	int	n_player;
	int	n_collec;

	i = 0;
	n_exit = 0;
	n_player = 0;
	n_collec = 0;
	while (map[i] || map[i] != '\n')
	{
		if ((line == 1 && map[i] != BORDER)
			|| (line == last_line && map[i] != BORDER)
			|| (line > 1 && line < last_line
			&& (map[0] != BORDER || map[ft_strlen(map) - 2] != BORDER)))
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
		else if (map[i] == EXIT)
			n_exit++;
		else if (map[i] == PLAYER)
			n_player++;
		else if (map[i] == COLLECTIBLE)
			n_collec++; 
		i++;
	}
	if (line == last_line && (n_exit != 1 || n_player != 1 || n_collec == 0))
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
}

static int	check_args(int ac, char **av, t_mapError *check)
{
	int	fd;

	if (ac != 2)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	check->max_call = 1;
	check->map = get_next_line(fd);
	fd = open(av[1], O_RDONLY);
	while (check->map)
	{
		free(check->map);
		check->map = get_next_line(fd);
		check->>max_call++;
	}
	close(fd);
	if (check->max_call <= 3)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	return (check->max_call);
}

void	read_map(int ac, char **av)
{
	int			fd;
	t_mapError	check;

	check.nb_call = 1;
	fd = open(av[1], O_RDONLY);
	check.max_call = check_args(ac, &av[1], &check);
	check.map = get_next_line(fd);
	while (check.map)
	{
		check_map_elems(check.nb_call, check.max_call);
		free(check.map);
		check.map = get_next_line(fd);
		check.nb_call++;
	}
	close(fd);
}
