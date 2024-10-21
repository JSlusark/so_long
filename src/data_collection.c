/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/21 19:27:53 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		printf("Problem with fetching game width and height!\n");
		free_map(map_array);
		exit(1);
	}
	map_data->height = h;
	map_data->width = w;
}

void	verify_format(char **map_array, t_map *level)
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
}
