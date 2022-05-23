#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "mlx_linux/mlx.h"
# include "../srcs/gnl/get_next_line.h"

# define FALSE 0
# define TRUE 1 
# define ESCAPE 65307
# define EXIT 'E'
# define GROUND '0'
# define BORDER '1'
# define COLLEC 'C'
# define PLAYER 'P'
# define ENEMIES 'N'
# define ELEMS "01CENP"
# define IMG_SIZE 64

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

typedef struct s_map
{
	int		nb_exit;
	int		nb_player;
	int		nb_collec;
	int		nb_lines;
	int		nb_columns;
	char	*str_line;
	char	**map;
}			t_map;

typedef struct s_textures
{
	t_image exit;
	t_image ground;
	t_image	border;
	t_image	collec;
	t_image	player;
	t_image	enemies;	
}			t_textures;

char	*ft_strchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
void	set_map(char **map, t_window *win);
void	read_map(int ac, char **av, t_map *map);
void	open_window(t_window *win, t_map *map);
void 	check_args(int ac, char **av);
void 	error_exit(void); // le changer de file
size_t	ft_strlen(const char *start);

#endif
