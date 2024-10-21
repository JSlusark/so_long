/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:31 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/21 09:07:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_algo(char **ffill_map, int y, int x, int *reach, t_map *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width
		|| ffill_map[x][y] == '1' || ffill_map[x][y] == ' ')
		return ;
	if (ffill_map[x][y] == 'C' || ffill_map [x][y] == 'E')
		(*reach)++; // this might be wring for e
	ffill_map[x][y] = ' ';
	fill_algo(ffill_map, x - 1, y, reach, level);
	fill_algo(ffill_map, x + 1, y, reach, level);
	fill_algo(ffill_map, x, y + 1, reach, level);
	fill_algo(ffill_map, x, y - 1, reach, level);
}
void verify_playability(t_map *level)
{
	int i;
	char **map_copy;

	// Allocate memory for the new map array (same number of rows as original)
	map_copy = malloc(sizeof(char *) * (level->height + 1));  // +1 for NULL-terminated row
	if (!map_copy)
	{
		printf("Error: Memory allocation failed for map copy\n");
		return;
	}

	// Copy each row of the map_array
	for (i = 0; i < level->height; i++)
	{
		map_copy[i] = strdup(level->map_array[i]);  // Duplicate each row
		if (!map_copy[i])
		{
			printf("Error: Memory allocation failed for map row\n");
			for (int j = 0; j < i; j++)
				free(map_copy[j]);
			free(map_copy);
			return;
		}
	}
	map_copy[level->height] = NULL;  // NULL-terminate the array

	// Initialize found_loot to track how many collectibles are reachable
	int found_loot = 1;
	// Get the player's initial position
	int y = level->character_data->curr_i->x;  // Correct coordinate access for row (height)
	int x = level->character_data->curr_i->y`;  // Correct coordinate access for column (width)

	// Start flood fill from the player's position
	fill_algo(map_copy, y, x, &found_loot, level);
	print_map(map_copy);  // Optional: to print the map after filling

	printf("Total reachable loot: %d\n", found_loot);

	// Free the copied map
	for (i = 0; i < level->height; i++) {
		free(map_copy[i]);
	}
	free(map_copy);
}





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

void verify_format(char **map_array, t_map *level)
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
	printf("Location: void verify_format(char **map_array, t_map *level)\n h:%d w:%d\n", level->height, level->width);
}
