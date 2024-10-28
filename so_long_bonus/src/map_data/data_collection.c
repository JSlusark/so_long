/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 22:20:46 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_fits_screen(int width, int height)
{
	Display	*d;
	Screen	*s;

	d = XOpenDisplay(NULL);
	if (d == NULL)
	{
		ft_printf("Error: Unable to open X display\n");
		return (0);
	}
	s = DefaultScreenOfDisplay(d);
	if (width * 64 > s->width || height * 64 > s->height)
	{
		ft_printf("Error: map resolution is bigger than your screen!\n");
		ft_printf("Screen width: %d map width: %d\n", s->width, width * 64);
		ft_printf("Screen height: %d map height: %d\n", s->height, height * 64);
		XCloseDisplay(d);
		return (0);
	}
	XCloseDisplay(d);
	return (1);
}

void	collect_size(char **map_array, t_map *map_data)
{
	int	h;
	int	w;

	h = 0;
	w = ft_strlen(map_array[h]);
	while (map_array[h] != NULL)
		h++;
	if (w == 0 || h == 0)
	{
		ft_printf("Problem with fetching game width and height!\n");
		free_map(map_array);
		exit(1);
	}
	map_data->height = h;
	map_data->width = w;
}

void	verify_format(char **map_array, t_map *level)
{
	collect_size(map_array, level);
	if (!map_fits_screen(level->width, level->height)
		|| !is_rectangular(map_array, level->width, level->height)
		|| !is_framed(map_array, level->height - 1, level->width - 1)
		|| !has_required_text(map_array)
		|| !has_enough_sprites(map_array, level))
	{
		free_map(level->map_array);
		free(level);
		exit(1);
	}
}
