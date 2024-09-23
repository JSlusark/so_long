/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:31 by jjs               #+#    #+#             */
/*   Updated: 2024/09/23 17:19:52 by jslusark         ###   ########.fr       */
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


//MAP
typedef struct s_map
{
	int	width;
	int height;
	// int p_n;  // can be used to make exit available when 0
	// t_coordinates p_position; // struct coords to use when finding the elements i need
	// int e_n;  // can be used to make exit available when 0
	// t_coordinates e_position;
	int c_n;  // can be used to make exit available when 0
	// t_coordinates c_position;
	// int f_n;  // can be used to make exit available when 0
}				t_map;

// typedef struct s_coordinates // could-+ save coords in another struct
// {
// 	t_coordinates *prev; // for colectible
// 	int col;
// 	int row;
// 	t_coordinates *next; // for colectible
// }				t_coordinates;

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