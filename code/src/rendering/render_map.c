/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:14:37 by jslusark          #+#    #+#             */
/*   Updated: 2025/08/13 11:55:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void render_moves(t_game *level)
{
	char *moves_text;
	char *lives_text;

	// Convert moves count to a string for display
	moves_text = ft_itoa(level->moves);
	lives_text = ft_itoa(level->lives);
	if (!moves_text)
		return; // Handle memory allocation failure

	// Display moves on the screen at coordinates (10, 10)
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   60, 20, 0xFFFFFF, moves_text);
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   100, 20, 0xFFFFFF, "Lives: ");
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   150, 20, 0xFFFFFF, lives_text);

	free(moves_text);
}
char *get_file(char c, t_game *level)
{
	if (c == '1')
		return (level->wall_img);
	else if (c == '0')
		return (level->floor_img);
	else if (c == 'P')
		return (level->character_img);
	else if (c == 'E')
		return (level->door_img);
	else if (c == 'C')
		return (level->loot_img);
	else if (c == 'K')
		return (level->enemy_img);
	return (NULL);
}

void render_map(void *img, char **map_array, t_game *level, t_lib lib)
{
	int y;
	int x;

	y = 0;
	while (map_array[y] != NULL)
	{
		x = 0;
		while (map_array[y][x] != '\0')
		{
			img = mlx_xpm_file_to_image(lib.game,
										get_file(map_array[y][x], level),
										&level->pixels, &level->pixels);
			if (img == NULL)
			{
				printf("Error: rendering textured to map failed\n");
				free_all_gamedata(level);
				exit(1);
			}
			mlx_put_image_to_window(lib.game, lib.session,
									img, x * level->pixels, y * level->pixels);
			mlx_destroy_image(lib.game, img);
			x++;
		}
		y++;
	}
}
