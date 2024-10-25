/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:26:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 15:10:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	allocate_chara_data(t_map *level)
{
	level->character_data = malloc(sizeof(t_sprite));
	if (!level->character_data)
	{
		free(level);
		exit(1);
	}
	level->character_data->curr_i = malloc(sizeof(t_coord));
	level->character_data->up_i = malloc(sizeof(t_coord));
	level->character_data->down_i = malloc(sizeof(t_coord));
	level->character_data->left_i = malloc(sizeof(t_coord));
	level->character_data->right_i = malloc(sizeof(t_coord));
	if (!level->character_data->curr_i || !level->character_data->up_i
		|| !level->character_data->down_i || !level->character_data->left_i
		|| !level->character_data->right_i)
	{
		free_all_gamedata(level);
		exit(1);
	}
}

int	create_map_dup(char **map_dup, t_map *level)
{
	int	i;

	i = 0;
	if (!map_dup)
	{
		ft_printf("Error: Memory allocation failed for map copy\n");
		return (0);
	}
	while (i < level->height)
	{
		map_dup[i] = ft_strdup(level->map_array[i]);
		if (!map_dup[i])
		{
			ft_printf("Error: failed strdup on line %i\n", i);
			return (0);
		}
		i++;
	}
	map_dup[level->height] = NULL;
	return (1);
}

void	allocate_map_dup(t_map *level)
{
	level->map_dup = malloc(sizeof(char *) * (level->height + 1));
	if (!create_map_dup(level->map_dup, level))
	{
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
}
