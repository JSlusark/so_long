/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/21 19:25:21 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_map_dup(char **map_dup, t_map *level)
{
	int i;

	i = 0;
	if (!map_dup)
	{
		printf("Error: Memory allocation failed for map copy\n");
		return (0);
	}
	while (i < level->height)
	{
		map_dup[i] = strdup(level->map_array[i]);
		if (!map_dup[i])
		{
			printf("Error: failed strdup on line %i\n", i);
			return(0);
		}
		i++;
	}
	map_dup[level->height] = NULL;
	return (1);
}

int	exit_was_reached(char **map_dup)
{
	int x;
	int y;

	x = 0;
	while (map_dup[x] != NULL)
	{
		while(map_dup[x][y] != '\0')
		{
			if(map_dup[x][y] == 'E') // if e is found it means that we were not able to fill it in loot_is_reachable
				return(0);
			y++;
		}
		y = 0;
		x++;
	}
	return(1);
}
int	loot_is_reachable(char **map_dup, int y, int x, int *reached_loot, t_map *level) // my floodfill
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
	{
		// printf("Out of bounds: tile[%d][%d]\n", x, y);
		return(0);
	}
	if (map_dup[x][y] == '1' || map_dup[x][y] == ' ')
	{
		// printf("Blocked or visited tile[%d][%d] letter %c\n", x, y, map_dup[x][y]);
		return(0);
	}
	if (map_dup[x][y] == 'C')
		(*reached_loot)++;
	// if (map_dup[x][y] == 'C' || map_dup[x][y] == '0' || map_dup[x][y] == 'P')
	map_dup[x][y] = ' ';
	// if (map_dup[x][y] == 'E' && (*reached_loot) == level->loot_n )
	// 	map_dup[x][y] = ' ';
	loot_is_reachable(map_dup, y, x - 1, reached_loot, level);
	loot_is_reachable(map_dup, y, x + 1, reached_loot, level);
	loot_is_reachable(map_dup, y - 1, x, reached_loot, level);
	loot_is_reachable(map_dup, y + 1, x, reached_loot, level);
	if ((*reached_loot) == level->loot_n )
		return(1);
	else
		return(0);
}
void verify_playability(t_map *level)
{
	int i;
	int reached_loot;
	char **map_dup;

	i = 0;
	map_dup = malloc(sizeof(char *) * (level->height + 1));
	if(!create_map_dup(map_dup, level))
	{
		free_map(map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	reached_loot = 0;
	int x = level->character_data->curr_i->x;  // Correct coordinate access for column (width)
	int y = level->character_data->curr_i->y;  // Correct coordinate access for row (height)
	print_map(map_dup);
	if(!loot_is_reachable(map_dup, y, x, &reached_loot, level) || !exit_was_reached(map_dup)) // problem when exit covers loot
	{
		print_map(map_dup);
		printf("Error: Either exit or loot is not reachable, loot not collected: %d \n", level->loot_n - reached_loot);
		free_map(map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	// print_map(map_dup);
	free(map_dup);// problem with freeing
}
