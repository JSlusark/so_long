/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/16 11:15:49 by jslusark         ###   ########.fr       */
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
		printf("Problem with fetching game width and height!\n");
		free_map(map_array);
		exit(1);
	}
	map_data->height = h;
	map_data->width = w;
	printf("Location:void	collect_size(char **map_array, t_map *map_data)\n h:%d w:%d\n", map_data->height, map_data->width);
}

void verify_map(char **map_array, t_map *level)
{
	collect_size(map_array, level);
	if (!has_required_text(map_array)
		||!is_rectangular(map_array, level->width, level->height)
		|| !is_framed(map_array, level->height - 1, level->width - 1)
		|| !has_enough_sprites(map_array, level))
	{
		free_all_gamedata(level);
		exit(1);
	}
	printf("Location: void verify_map(char **map_array, t_map *level)\n h:%d w:%d\n", level->height, level->width);
}
