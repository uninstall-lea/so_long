#include "so_long.h"

static void	check_args(int ac, char **av, t_mapError *check)
{
	int	fd;

	if (ac != 2)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	check->last_line = 1;
	fd = open(av[1], O_RDONLY);
	check->map = get_next_line(fd);
	while (check->map)
	{
		free(check->map);
		check->map = get_next_line(fd);
		check->last_line++;
	}
	close(fd);
	if (check->last_line <= 3)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
}

static void	check_map_elems(t_mapError *check)
{
	int	i;

	i = 0;
	while (check->map[i] && check->map[i] != '\n')
	{
		if (ft_strchr(ELEMS, check->map[i]) == 0)
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
		else if (check->map[i] == EXIT)
			check->n_exit++;
		else if (check->map[i] == PLAYER)
			check->n_player++;
		else if (check->map[i] == COLLECTIBLE)
			check->n_collec++; 
		i++;
	}
	if (check->line == check->last_line - 1 && (check->n_exit != 1
		|| check->n_player != 1 || check->n_collec == 0))
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
}

static void	check_map_borders(int line, int last_line, char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if ((map[i] != BORDER && (line == 1 || line == last_line))
			|| (line > 1 && line < last_line
			&& (map[0] != BORDER || map[ft_strlen(map) - 2] != BORDER)))
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
		i++;
	}
}

void	read_map(int ac, char **av)
{
	int			fd;
	t_mapError	check;

	check.line = 1;
	check.n_exit = 0;
	check.n_player = 0;
	check.n_collec = 0;
	check_args(ac, av, &check);
	fd = open(av[1], O_RDONLY);
	check.map = get_next_line(fd);
	while (check.map)
	{
		check_map_elems(&check);
		check_map_borders(check.line, check.last_line, check.map);
		free(check.map);
		check.map = get_next_line(fd);
		check.line++;
	}
	close(fd);
}
