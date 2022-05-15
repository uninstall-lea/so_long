#include "so_long.h"

void	check_map_elems(int line, int last_line, char *map)
{
	int	i;
	int	nb_exit;
	int	nb_player;
	int	nb_collectible;

	i = 0;
	nb_exit = 0;
	nb_player = 0;
	nb_collectible = 0;
	while (map[i])
	{
		if ((line == 1 && map[i] != BORDER)
			|| (line == last_line && map[i] != BORDER)
			|| map[0] != BORDER || map[ft_strlen(map) - 1] != BORDER)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else if (map[i] == EXIT)
			nb_exit++;
		else if (map[i] == PLAYER)
			nb_player++;
		else if (map[i] == COLLECTIBLE)
			nb_collectible++; 
		i++;
	}
	if (nb_exit != 1 || nb_player != 1 || nb_collectible == 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	read_map(int ac, char **av)
{
	int		fd;
	int		nb_call;
	int		max_call;
	char	*map;

	if (ac != 3)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	max_call = 1;
	fd = open(av[1], O_RDONLY);
	map = get_next_line(fd);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		max_call++;
	}
	close(fd);
	nb_call = 1;
	fd = open(av[1], O_RDONLY);
	map = get_next_line(fd);
	while (map)
	{
		check_map_elems(nb_call, max_call, map);
		free(map);
		map = get_next_line(fd);
		nb_call++;
	}
	close(fd);
}
