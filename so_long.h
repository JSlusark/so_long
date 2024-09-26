/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:31 by jjs               #+#    #+#             */
/*   Updated: 2024/09/26 11:10:29 by jslusark         ###   ########.fr       */
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
# define VALID_CHARS "01PCE"
# define WALL "1"
# define CHARACTER "P"
# define LOOT "C"
# define EXIT "E"
# define FLOOR "0"


//MAP
typedef struct s_map
{
	int	width;
	int height;
	int loot_n;  // can be used to make exit available when 0
	t_sprite **character_data;
	char	*character_img;
	char	*exit_img;
	char	*floor_img;
	char	*loot_img;
	char	*wall_img;
	int last_c;
	int	last_r;
}				t_map;

typedef struct s_sprite // could-+ save coords in another struct
{
	char *ptr;
	int moves;
	int	loot_collected;
	t_coord **curr_i;
	t_coord **up_i; // stores chara top of image if applicable
	t_coord **left_i; // stores chara left of image if applicable
	t_coord **right_i; // stores chara right of image if applicable
	t_coord **down_i; // stores chara bottom of image if applicable
}				t_sprite;

typedef struct s_coord // could-+ save coords in another struct
{
	char *ptr;
	int x; // so that then i can change these
	int y;
}				t_coord

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


#endif