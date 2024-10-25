/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:31 by jjs               #+#    #+#             */
/*   Updated: 2024/10/25 15:06:22 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//MACROS
# define BUFFER_SIZE 42
# define PIXELS 64
# define UP_KEY 65362 //<---------- can i use define?
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Q_KEY 113
// # define VALID_CHARS "01PCE"
// # define WALL "1"
// # define CHARACTER "P"
// # define LOOT "C"
// # define EXIT "E"
// # define FLOOR "0"

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

typedef struct s_lib
{
	void	*game;
	void	*session;
	void	*img;
}				t_lib;

typedef struct s_coord
{
	char	*ptr;
	int		x;
	int		y;
}				t_coord;

typedef struct s_sprite
{
	char	*ptr;
	t_coord	*curr_i;
	t_coord	*up_i;
	t_coord	*left_i;
	t_coord	*right_i;
	t_coord	*down_i;
}				t_sprite;

typedef struct s_map
{
	t_lib		mini_libx;
	char		**map_array;
	char		**map_dup;
	int			width;
	int			height;
	int			pixels;
	int			loot_n;
	int			moves;
	t_sprite	*character_data;
	char		*character_img;
	char		*door_img;
	char		*floor_img;
	char		*loot_img;
	char		*wall_img;
	int			last_c;
	int			last_r;
}				t_map;

char			**get_map(char *file, t_map *map_data);
char			*get_next_line(int fd);
void			collect_size(char **map_array, t_map *map_data);
void			verify_format(char **map_array, t_map *map_data);
void			verify_playability(t_map *level);
int				has_required_text(char **map); // handles invalid characters
int				has_enough_sprites(char **map, t_map *map_data);
int				is_rectangular(char **map, int row, int col);
int				is_framed(char **map, int last_row, int last_c);
void			allocate_chara_data(t_map *level);
void			allocate_map_dup(t_map *level);
void			free_map(char **map_layout);
void			free_sprite(t_sprite *character_data);
void			free_all_gamedata(t_map *level);
void			collect_sprites(char **map_array, t_map *map_data);
void			get_chara_position(char **map_array, t_sprite *chara);
void			render_map(void *img, char **map_array,
					t_map *level, t_lib mini_libx);
void			change_map(char *direction, char *character, t_map *level);

int				key_hook(int keycode, t_map	*level);
int				close_window(t_map *level);

// testing functions
// void			print_chara_data(t_sprite *c);
// void			print_map(char **map_array);
#endif
