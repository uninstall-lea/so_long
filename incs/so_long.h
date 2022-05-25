#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include "../srcs/gnl/get_next_line.h"

/* MAP ELEMS */
# define ELEMS "01CNEP"
# define OBSTACLE "1E"
# define GROUND '0'
# define BORDER '1'
# define COLLEC 'C'
# define ENEMIES 'N'
# define EXIT 'E'
# define PLAYER 'P'

/* KEYCODE */
# define ESCAPE 65307
# define W 122
# define A 113
# define S 115
# define D 100

/* DEFINE VALUES */
# define TRUE 1 
# define FALSE 0
# define IS_ELEM TRUE
# define NOT_ELEM FALSE
# define CAN_MOVE TRUE
# define CANT_MOVE FALSE
# define IMG_SIZE 64

typedef struct s_window
{
	int		w;
	int		h;
	void	*mlx;
	void	*win_ptr;
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

typedef struct s_player
{
	int	x;
	int	y;
}			t_player;

/* STRINGS */
char	*ft_strchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
size_t	ft_strlen(const char *start);

/* MAP */
void	check_map_borders(int line, char *map, t_map *check);
void	check_map_elems(int line, char *map , t_map *check);
void	check_map_size(char **av, t_map *check);
void	init_map(int ac, char **av, t_map *map);
void 	check_args(int ac, char **av);

/* TEXTURES */
void	display_img(char **map, t_window *win, t_textures *set);

/* WINDOW */
void	open_window(t_window *win, t_map *map);

/* OTHER UTILS */
void 	error_exit(void);
void	get_coordinates(char to_find, char **map, void *to_init);

#endif
