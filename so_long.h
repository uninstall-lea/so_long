#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "mlx_linux/mlx.h"
# include "./gnl/get_next_line.h"


# define ESCAPE 65307
# define EXIT 'E'
# define PLAYER 'P'
# define BORDER '1'
# define COLLECTIBLE 'C'

typedef struct s_window
{
	int		w;
	int		h;
	void	*mlx;
	void	*mlx_win;
}			t_window;

typedef struct s_image
{
	int		w;
	int		h;
	char	*path;
	void	*img;
}			t_image;

typedef struct s_mapError
{
	int		nb_call;
	int		max_call;
	char	*map;
}			t_mapError;

void	set_image(t_window *win);
void	open_window(t_window *win);
void	read_map(int ac, char **av);
size_t	ft_strlen(const char *start);

#endif
