/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:42:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/23 12:27:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_sprite(t_sprite *character_data)
{
	if (character_data != NULL)
	{
		// Free all dynamically allocated t_coord pointers within the t_sprite
		free(character_data->curr_i);
		free(character_data->up_i);
		free(character_data->down_i);
		free(character_data->left_i);
		free(character_data->right_i);

		// Finally, free the t_sprite struct itself
		free(character_data);
	}
}
void	free_map(char **map_layout)
{
	int	i;

	if (!map_layout)  // Ensure map_layout itself is not NULL
		return;
	i = 0;
	while (map_layout[i])
	{
		free(map_layout[i]);
		i++;
	}
	free(map_layout);
}
void	free_all_gamedata(t_map *level)
{
 //THIS FREES ALL THE MINILIBX STUFF (GMAE AND SESSION)
	if(level->mini_libx.game)
	{
		mlx_clear_window(level->mini_libx.game, level->mini_libx.session);
		mlx_destroy_window(level->mini_libx.game, level->mini_libx.session);  // Free the window
		mlx_destroy_display(level->mini_libx.game);
		free(level->mini_libx.game);
	}
	// MY STUFF

	free_sprite(level->character_data);
	free_map(level->map_array);
	free(level);
}


// print map data
	// printf("first line map_array %s..\n", map_array[0]);
	// printf("character file path %s\n", level->character_img);
	// printf("w: %d h: %d\n", level->width, level->height);
	// printf("tile_pixel: %d\n", level->pixels);
