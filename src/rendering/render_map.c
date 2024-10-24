/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:14:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/24 19:50:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map(void *img, char **map_array, t_map *level, void *game, void * session)
{
	int	y;
	int	x;

	y = 0;
		while (map_array[y] != NULL)
	{
		x = 0;
		while (map_array[y][x] != '\0')
		{
			if (map_array[y][x] == '1')
				img = mlx_xpm_file_to_image(game, level->wall_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == '0')
				img = mlx_xpm_file_to_image(game, level->floor_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'P')
				img = mlx_xpm_file_to_image(game, level->character_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'E')
				img = mlx_xpm_file_to_image(game, level->door_img, &level->pixels, &level->pixels);
			else if (map_array[y][x] == 'C')
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
	if (*direction == '1')
		return ;
	else if (*direction == 'E' && level->loot_n != 0)
		return ;
	else if (*direction == 'E' && level->loot_n == 0)
	{
		level->moves++;
		printf("STEPS: %d\n", level->moves);
		printf("YOU WON!\n");
		free_all_gamedata(level);
		exit(0);
	}
	else if (*direction == 'C')
		level->loot_n--;
	level->moves++;
	printf("STEPS: %d\n", level->moves);
	*direction = *character;
	*character = '0';
}
