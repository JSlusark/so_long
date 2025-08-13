/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2025/08/13 12:24:40 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

#ifdef __APPLE__
#include <CoreGraphics/CGDisplayConfiguration.h>
#endif

int map_fits_screen(int width, int height)
{
	int screen_width;
	int screen_height;

#ifdef __APPLE__
	// for mac os build
	screen_width = CGDisplayPixelsWide(CGMainDisplayID());
	screen_height = CGDisplayPixelsHigh(CGMainDisplayID());
#else
	// for Linux build with X11
	Display *d;
	Screen *s;

	d = XOpenDisplay(NULL);
	if (d == NULL)
	{
		ft_printf("Error: Unable to open X display\n");
		return (0);
	}
	s = DefaultScreenOfDisplay(d);
	screen_width = s->width;
	screen_height = s->height;
	XCloseDisplay(d);
#endif

	if (width * 64 > screen_width || height * 64 > screen_height)
	{
		ft_printf("Error: map resolution is bigger than your screen!\n");
		ft_printf("Screen width: %d map width: %d\n", screen_width, width * 64);
		ft_printf("Screen height: %d map height: %d\n", screen_height, height * 64);
		return (0);
	}
	return (1);
}

void collect_size(char **map_array, t_game *map_data)
{
	int h;
	int w;

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
	printf("MAP %d: \n h:%d w:%d\n", map_data->level_i, map_data->height, map_data->width);
}

void verify_format(char **map_array, t_game *level)
{
	collect_size(map_array, level);
	if (!map_fits_screen(level->width, level->height) || !is_rectangular(map_array, level->width, level->height) || !is_framed(map_array, level->height - 1, level->width - 1) || !has_required_text(map_array) || !has_enough_sprites(map_array, level))
	{
		free_map(level->map_array);
		free(level);
		exit(1);
	}
}
