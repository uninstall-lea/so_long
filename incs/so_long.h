/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:58:48 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 21:25:03 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "mlx_linux/mlx.h"
# include "../srcs/gnl/get_next_line.h"

/* DEFINE VALUES */
# define TRUE 1
# define FALSE 0
# define ERROR 0
# define IMG_SIZE 64
# define ON_DESTROY 17
# define NOT_FOUND 404
# define NO_MORE_COLLECTIBLE_LEFT 0
# define BANG_BANG_YOU_SHOT_ME_DOWN 666

/* DEFINE RGB */
# define RED 0
# define GREEN 1
# define BLUE 2

/* MAP ELEMS */
# define EXIT 'E'
# define ENEMY 'N'
# define GROUND '0'
# define BORDER '1'
# define COLLEC 'C'
# define PLAYER 'P'
# define ELEMS "01CNEP"
# define OBSTACLE "1CEN"

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

/* DEFINE KEYWORD */
# define YES TRUE
# define NO FALSE
# define IS_ELEM TRUE
# define NOT_ELEM FALSE
# define CAN_MOVE TRUE
# define CANT_MOVE FALSE
# define NOT_CLOSED FALSE
# define NOT_RECTANGLE FALSE
# define CAN_GO_TO_PONEY TRUE
# define CANT_GO_TO_PONEY FALSE

/* TYPEDEF */
typedef void	(*t_fptr)();

/* STRUCTS */
typedef struct s_window
{
	int		h;
	int		w;
	void	*mlx;
	void	*win_ptr;
}			t_window;

typedef struct s_image
{
	char	*path;
	int		h;
	int		w;
	void	*img;
}			t_image;

typedef struct s_map
{
	char	**str_map;
	char	*str_line;
	int		nb_collec;
	int		nb_columns;
	int		nb_exit;
	int		nb_lines;
	int		nb_player;
	int		nb_enemy;
}			t_map;

typedef struct s_textures
{
	t_image	border;
	t_image	collec;
	t_image	player;
	t_image	exit;
	t_image	ground;
	t_image	red_enemy;
	t_image	blue_enemy;
	t_image	green_enemy;
}			t_textures;

typedef struct s_player
{
	long int	x;
	long int	y;
	int			nb_moves;
}			t_player;

typedef struct s_enemy
{
	int			dir;
	int			rgb;
	long int	x;
	long int	y;
}			t_enemy;

typedef struct s_time
{
	clock_t	begin;
	clock_t	end;
	int		current;
	int		previous;
}				t_time;

typedef struct s_data
{
	t_window	win;
	t_map		map;
	t_textures	pack;
	t_time		time;	
	t_enemy		*enemy;
	t_player	player;	
}				t_data;

/* PROTOTYPES */
/* MAP */
int		check_map_elems(int line, char *map, t_map *check);
int		check_map_borders(int line, char *map, t_map *check);
void	check_arg(int ac, char **av, t_map *check);
void	init_map(int ac, char **av, t_data *data);
void	update_map_for_enemy(char how, char **map, t_enemy *e);
void	update_map_for_player(char where, char how, char **map, t_player *p);

/* TEXTURES */
void	bisson_rgb(t_enemy *enemy, t_data *data);
void	display_img(char **map, t_window *win, t_textures *set, t_data *data);
void	destroy_img(t_window *win, t_textures *pack);

/* WINDOW */
int		close_window(t_data *data);
void	open_window(t_window *win, t_map *map);
void	put_img_to_window(int x, int y, t_window *win, t_image to_put);

/* EVENTS */
int		hook_events(int keycode, t_data *data);
void	move_up(char **map, t_player *player, t_data *data);
void	move_left(char **map, t_player *player, t_data *data);
void	move_down(char **map, t_player *player, t_data *data);
void	move_right(char **map, t_player *player, t_data *data);

/* MOVES */
	/* PLAYER */
int		can_i_go_to_poney(char **map, t_player *player, t_data *data);
int		can_i_increase_p(char where, char **map,
			t_player *player, t_data *data);
int		can_i_decrease_p(char where, char **map,
			t_player *player, t_data *data);
void	loose_if_p_walk_on_e(char **map, t_player *p, t_data *data);
void	get_coordinates_player(char **map, t_player *to_init);
	/* THE BAD GUYS */
int		can_i_decrease_e(char **map, t_enemy *enemy);
int		can_i_increase_e(char **map, t_enemy *enemy);
int		has_enough_time_passed(t_time *time);
int		pat_patrol(t_data *data);
void	set_up_time(t_time *time);
void	set_up_enemies(t_data *data);
void	get_coordinates_enemy(char **map, t_enemy *to_init);
void	if_obstacle_change_dir(t_enemy *enemy, t_data *data);
void	loose_if_e_walk_on_p(char **map, t_enemy *e, t_data *data);

/* UTILS */
	/* ARRAY */
int		find_index(int *arr, int size, int to_find);
char	*ft_strchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
size_t	ft_strlen(const char *start);
void	ft_free(char **str);
	/* PRINT */
void	count_and_print_my_moves(t_data *data);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	error_exit(int error);

#endif
