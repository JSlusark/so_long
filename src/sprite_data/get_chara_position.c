/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chara_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 11:02:08 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	assign_direction_data(char **map_array, t_coord *character_coords,
t_coord *direction_coords, char *direction)
{
	if (strcmp(direction, "up") == 0)
	{
		direction_coords->x = character_coords->x - 1; // Update x by reference
		direction_coords->y = character_coords->y;
	}
	else if (strcmp(direction, "down") == 0)
	{
		direction_coords->x = character_coords->x + 1;
		direction_coords->y = character_coords->y;
	}
	else if (strcmp(direction, "left") == 0)
	{
		direction_coords->x = character_coords->x;
		direction_coords->y = character_coords->y - 1;
	}
	else if (strcmp(direction, "right") == 0)
	{
		direction_coords->x = character_coords->x;
		direction_coords->y = character_coords->y + 1;
	}
	direction_coords->ptr = &map_array[direction_coords->x]
	[direction_coords->y];
}

void	*assign_character_data(char **map_array, int r, int c,
t_sprite *character_data)
{
	character_data->ptr = &map_array[r][c];
	character_data->curr_i = malloc(sizeof(t_coord));
	if (!character_data->curr_i)
	{
		free(character_data);
		return (NULL);
	}
	character_data->curr_i->ptr = &map_array[r][c];
	character_data->curr_i->x = r;
	character_data->curr_i->y = c;
	return (character_data);
}

void	get_chara_position(char **map_array, t_map *level)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	level->character_data = malloc(sizeof(t_sprite));
	level->character_data->up_i = malloc(sizeof(t_coord));
	level->character_data->down_i = malloc(sizeof(t_coord));
	level->character_data->left_i = malloc(sizeof(t_coord));
	level->character_data->right_i = malloc(sizeof(t_coord));
	while (map_array[r] != NULL)
	{
		c = 0;
		while (map_array[r][c] != '\0')
		{
			if (map_array[r][c] == 'P')
				assign_character_data(map_array, r, c, level->character_data);
			c++;
		}
		r++;
	}
	assign_direction_data(map_array, level->character_data->curr_i, level->character_data->up_i, "up");
	assign_direction_data(map_array, level->character_data->curr_i, level->character_data->down_i, "down");
	assign_direction_data(map_array, level->character_data->curr_i, level->character_data->left_i, "left");
	assign_direction_data(map_array, level->character_data->curr_i, level->character_data->right_i, "right");
}
