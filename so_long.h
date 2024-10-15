/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:31 by jjs               #+#    #+#             */
/*   Updated: 2024/10/15 17:32:37 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

//sprites size
# define SIZE 32
#define UP_KEY 65362 //<---------- can i use define?
#define DOWN_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define Q_KEY 113
// # define VALID_CHARS "01PCE"
// # define WALL "1"
// # define CHARACTER "P"
// # define LOOT "C"
// # define EXIT "E"
// # define FLOOR "0"
typedef struct	s_lib {
	void	*game;
	void	*session;
	void	*img;
}				t_lib;

typedef struct s_coord // could-+ save coords in another struct
{
	char *ptr;
	int x; // so that then i can change these
	int y;
}				t_coord;

typedef struct s_sprite // could-+ save coords in another struct
{
	char *ptr; // it has to be a pointer because i want to change the char in the address
	// int moves;
	// int	loot_collected;
	t_coord *curr_i;
	t_coord *up_i; // stores chara top of image if applicable
	t_coord *left_i; // stores chara left of image if applicable
	t_coord *right_i; // stores chara right of image if applicable
	t_coord *down_i; // stores chara bottom of image if applicable
}				t_sprite;


typedef struct s_map
{
	t_lib mini_libx;
	char **map_array;
	int	width;
	int height;
	int pixels;
	int loot_n;  // can be used to make exit available when 0
	// int	loot_collected;
	int moves;
	t_sprite *character_data;
	char	*character_img;
	char	*door_img;
	char	*floor_img;
	char	*loot_img;
	char	*wall_img;
	int last_c;
	int	last_r;
}				t_map;


// Map parsing (to transform in array)
char	**get_map(char *file, t_map *map_data); // handles fd errors, invalid and empty files
char	*get_next_line(int fd); // collects map's text into an array that is split and used for validation
// Map data collection - verifies map is valid and collects some data used further
void	collect_size(char **map_array, t_map *map_data); // collects map size
void	verify_map(char **map_array, t_map *map_data); // uses map validation below and collects collectable amount
// Map validation (returns true or false)
int		has_required_text(char **map); // handles invalid characters
int		has_enough_sprites(char **map, t_map *map_data); // makes sure there is the correct amount of assets required
int		count_sprites(char **map, int *f, int *e, int *c, int *p);
int		is_rectangular(char **map, int row, int col); // checks shape is rectangular
int		is_framed(char **map, int last_row, int last_c); // checks maps os framed by wall sprites
// Memory handling
void	free_map(char **map_layout);
//Sprites img handling
void	collect_sprites(char **map_array, t_map *map_data); //collects sprites path in map struct
void	init_chara_data(char **map_array, t_map *map_data); // could be used to update array after char movement
//Map rendering
void	render_map(void *img, char **map_array, t_map *level, void *game, void * session);
void	change_map(char *direction, char *character, t_map *level);

// testing function
void print_chara_data(t_sprite *c);

#endif
