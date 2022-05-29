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
# define GROUND '0'
# define BORDER '1'
# define COLLEC 'C'
# define ENEMIES 'N'
# define EXIT 'E'
# define PLAYER 'P'

/* KEYCODE */
# define ESC 65307
# define UP 65362
# define W 119
# define Z 122
# define LEFT 65361
# define A 97
# define Q 113
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100

/* DEFINE VALUES */
# define TRUE 1 
# define FALSE 0
# define NOT_FOUND 404
# define IS_ELEM TRUE
# define NOT_ELEM FALSE
# define CAN_MOVE TRUE
# define CANT_MOVE FALSE
# define NO_MORE_COLLECTIBLE_LEFT 0
# define CAN_GO_TO_PONEY TRUE
# define CANT_GO_TO_PONEY FALSE
# define IMG_SIZE 64

typedef void	(*t_fptr)();

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

typedef struct s_data
{
	int		nb_moves;
	t_map		map;
	t_window	win;
	t_textures	pack;
	t_player	player;
}				t_data;

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
void    destroy_img(t_window *win, t_textures *pack);

/* WINDOW */
void	open_window(t_window *win, t_map *map);

/* EVENTS */
int		handle_events(int keycode, t_data *data);
void	move_up(char **map, t_data *data);
void	move_left(char **map, t_data *data);
void	move_down(char **map, t_data *data);
void	move_right(char **map, t_data *data);
void	close_window(t_data *data);

/* MOVES ACCESSIBILITY */
int		check_accessibility(char c, t_data *data);
int 	decrease(char where, char **map, t_data *data);
int 	increase(char where, char **map, t_data *data);
void	check_for_exit(char **map, t_data *data);
void	check_for_collec(char **map, t_data *data);

/* OTHER UTILS */
int		ft_intchr(int *arr, int size, int to_find);
void 	error_exit(void);
void	ft_free(char **str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	count_and_print_my_moves(t_data *data);
void	get_coordinates(char to_find, char **map, t_player *to_init);
void	put_img_to_window(int x, int y, t_window *win, t_image to_put); //la changer de fichier

#endif
