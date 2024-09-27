/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/27 18:23:00 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_size(char **map_array, t_map *map_data)
{
	int h;
	int w;
	h = 0;
	w = ft_strlen(map_array[h]);
	while (map_array[h] != NULL)
		h++;
	if (w == 0 || h == 0)
	{
		free_map(map_array);
		exit(1);
	}
	map_data->height = h;
	map_data->width = w;
}

void verify_map(char **map_array, t_map *map_data)
{
	collect_size(map_array, map_data);
	if (!has_required_text(map_array)
		||!is_rectangular(map_array, map_data->width, map_data->height)
		|| !is_framed(map_array, map_data->height - 1, map_data->width - 1)
		|| !has_enough_sprites(map_array, map_data))
	{
		// this should handle also other problems like map being too small or spaces
		free_map(map_array);
		exit(1);
	}
	// collect_sprites_position(map_data, map_array); // collects protagonist position
}
