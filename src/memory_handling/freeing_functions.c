/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:42:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 18:48:24 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_sprite(t_sprite *character_data)
{
	if (character_data != NULL)
	{
		free(character_data->curr_i);
		free(character_data->up_i);
		free(character_data->down_i);
		free(character_data->left_i);
		free(character_data->right_i);
		free(character_data);
	}
}

void	free_map(char **map_layout)
{
	int	i;

	if (!map_layout)
		return ;
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
	if (level->mini_libx.game)
	{
		mlx_clear_window(level->mini_libx.game, level->mini_libx.session);
		mlx_destroy_window(level->mini_libx.game, level->mini_libx.session);
		mlx_destroy_display(level->mini_libx.game);
		free(level->mini_libx.game);
	}
	free_sprite(level->character_data);
	free_map(level->map_array);
	free(level);
}
