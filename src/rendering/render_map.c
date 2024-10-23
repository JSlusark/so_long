/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:14:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/23 12:29:57 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map(void *img, char **map_array, t_map *level, void *game, void * session)
{
	int y;
	int x;

	y = 0;
		while (map_array[y] != NULL)
	{
		x = 0;
		while (map_array[y][x] != '\0')
		{
			if (map_array[y][x] == '1') // Wall
				img = mlx_xpm_file_to_image(game, level->wall_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == '0') // Floor
				img = mlx_xpm_file_to_image(game, level->floor_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'P') // Character
				img = mlx_xpm_file_to_image(game, level->character_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'E') // Exit
				img = mlx_xpm_file_to_image(game, level->door_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'C') // Loot
				img = mlx_xpm_file_to_image(game, level->loot_img, &level->pixels, &level->pixels);
			if (img != NULL)
			{
				mlx_put_image_to_window(game, session, img, x * level->pixels, y * level->pixels);
				mlx_destroy_image(game, img);
			}
			x++;
		}
		y++;
	}
}

void	change_map(char *direction, char *character, t_map *level)
{
	if(*direction == '1')
	{
		// printf("STEPS: %d\n", level->moves);
		return;
	}
	else if(*direction == 'E' && level->loot_n != 0)
	{
		// printf("STEPS: %d\n", level->moves);
		return;
	}
	else if(*direction == 'E' && level->loot_n == 0)
	{
		level->moves++;
		printf("STEPS: %d\n", level->moves); // count last step before closing
		printf("YOU WON!\n"); // count last step before closing
		free_all_gamedata(level);
		exit(0);
	}
	else if(*direction == 'C')
		{
			// printf("LOOT N: %d\n", level->loot_n);
			level->loot_n--;
		}
	level->moves++;
	printf("STEPS: %d\n", level->moves);
			// return; // and exit? or return number to decide?
	*direction = *character;
	*character = '0';
}
