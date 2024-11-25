/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:44:13 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/02/13 12:05:42 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include "../include/mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

# define W 119
# define UP 65362
# define S 115
# define DOWN 65364
# define A 97
# define LEFT 65361
# define D 100
# define RIGHT 65363

# define ESC 65307
# define Q 113

# define BLOCK 64
# define ELEMENTS "01CEPBG"
# define NBR_OF_IMGS 18

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_element
{
	int		x;
	int		y;
	t_image	img;
}	t_element;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_coin
{
	int		loop;
	int		pos_coin;
	t_image	img;
}	t_coin;

typedef struct s_goblin
{
	int		x;
	int		y;
	char	c;
	t_image	img;
}	t_goblin;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**cpy_map;
	int			map_h;
	int			map_l;
	int			n_collect;
	int			n_player;
	int			n_exit;
	int			n_floor;
	int			n_moves;
	int			n_goblins;
	char		*s_moves;
	int			endgame;
	int			loop;
	t_image		canva;
	t_image		imgs[NBR_OF_IMGS];
	t_element	player;
	t_element	door;
	t_goblin	*goblin;
	t_coin		coin;
}	t_data;

typedef enum e_type
{
	PLAYER_LEFT_,
	PLAYER_RIGHT_,
	PLAYER_UP_,
	PLAYER_DOWN_,
	GOBLIN_LEFT_,
	GOBLIN_RIGHT_,
	GOBLIN_UP_,
	GOBLIN_DOWN_,
	BARREL_,
	COINS_0_,
	COINS_1_,
	COINS_2_,
	COINS_3_,
	FLOOR_1_,
	WALL_1_,
	DOOR_CLOSED_,
	DOOR_OPENED_,
}	t_type;

int				close_window(t_data *data);
int				keypress(int keycode, t_data *data);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_image *data, int x, int y);
void			my_mlx_put_image(t_image *image, t_image *canva,
					int sx, int sy);
void			load_image(char *path, t_image *img, void *mlx_ptr);
void			load_all_images(t_data *data);
size_t			ft_strlen(const char *str);
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			read_map(char *path, t_data *data);
void			game_init(t_data *data);
int				draw_map(t_data *data);
void			player_w(t_data *data);
void			player_s(t_data *data);
void			player_a(t_data *data);
void			player_d(t_data *data);
int				ft_findchar(char c, char *str);
int				map_checker(t_data *data);
void			map_size(t_data *data);
void			player_position(t_data *data);
int				check_path(t_data *data);
void			free_map(char **map);
int				ft_printf(const char *str, ...);
int				animation(t_data *data);
char			*ft_itoa(int n);
void			elements_init(t_data *data);
void			enemies_walk(t_data *data);
int				check_num_elemnts(t_data *data);
void			load_all_images2(t_data *data);

#endif