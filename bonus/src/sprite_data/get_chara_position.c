/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chara_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 12:46:19 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	assign_direction_data(char **map_array, t_coord *character_coords,
t_coord *direction_coords, char *direction)
{
	if (strcmp(direction, "up") == 0)
	{
		direction_coords->x = character_coords->x - 1;
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

void	get_chara_position(char **map_array, t_sprite *chara)
{
	int	r;
	int	c;

	r = 0;
	while (map_array[r] != NULL)
	{
		c = 0;
		while (map_array[r][c] != '\0')
		{
			if (map_array[r][c] == 'P')
				assign_character_data(map_array, r, c, chara);
			c++;
		}
		r++;
	}
	assign_direction_data(map_array, chara->curr_i, chara->up_i, "up");
	assign_direction_data(map_array, chara->curr_i, chara->down_i, "down");
	assign_direction_data(map_array, chara->curr_i, chara->left_i, "left");
	assign_direction_data(map_array, chara->curr_i, chara->right_i, "right");
}
