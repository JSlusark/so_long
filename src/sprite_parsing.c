/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/26 15:40:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// looping to thorugh the array so that when we find the character we will create its own struct (t_characrter) that stores information about itself and the tiles surrounding it
// this info can be used to update the map array when the character moves and interacts with the map
// FUNCTIONS WERE JUST DRAFTED WHILE THINKING ABOUT THE PROCESS/LOGIC, MAKE SURE LOGIC WORKS AND MAKES SENSE

void	find_direction_coords(t_coord character_coords, char *direction, int x, int y); // func can be used once wit ahh assets
{
	if(direction == "up") // i do not need to hadle in the even coors are outside the map as chara will alsways be framed by unpassable walls
	{
		x = character_coords->x - 1; // WE MOVE UP of one row of chara, therefore x - 1
		y = character_coords->y; // we are still in the same col (y axis) of chara
	}
	if(direction == "down")
	{
		x = character_coords->x + 1; // WE MOVE DOWN of one row of chara, therefore x + 1
		y = character_coords->y; // we are still in the same col (y axis) of chara
	}
	if(direction == "left")
	{
		x = character_coords->y - 1;  // WE MOVE LEFT thorugh y axis of chara therefore y - 1
		y = character_coords->x; // we are still in the same row (x axis) of chara
	}
	if(direction == "right")
	{
		x = character_coords->y + 1;  // WE MOVE RIGHT thorugh y axis of chara therefore y + 1
		y = character_coords->x; // we are still in the same row (x axis) of chara
	}
}

t_coord	assign_direction_data(char **map_array, t_coord character_coords, t_coord direction_coords, char *direction); // func can be used once wit ahh assets
{
	int row;
	int col;
	t_coord direction_coords;

	find_direction_coords(character_coords, direction, row, col); // func can be used once wit ahh assets
	direction_coords->ptr = map_array[row][col];
	if(direction_coords->ptr  == NULL )
	{
		direction_coors->x = NULL;
		direction_coors->y = NULL;
		direction_coords = NULL
		printf("ERROR: character should be surrounded by elements\n")
		printf("-----> Direction %s, array[%d][%d]\n", direction, row, col);
	}
	else
	{
		direction_coors->x = row;
		direction_coors->y = col;
	}
	return(direction_coords);
}

t_sprite	assign_character_data()
{
	t_sprite	character_data;

	character_data->ptr = map_array[r][c]; // we have the letter and also address of sprite
	character_data->moves = 0; //needed only for chara
	character_data->loot_collected = 0; //needed only for chara

	character_data->curr_i->ptr = map_array[r][c];
	character_data->curr_i->x = r;
	character_data->curr_i->y = c;
}

void	create_chara_data(char **map_array, t_map map_data) // could be used to update array after char movement
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (map_array[r] != NULL)
	{
		c = 0;
		while (map_array[r][c] != "\0")
		{
			if(map_array[r][c] == "P")
				map_data->character_data = assign_character_data(map_array, r, c);
			c++;
		}
		r++;
	}
	map_data->character_data->up_i = assign_direction_data(map_array, map_data->character_data->curr_i, character_data->up_i, "up");
	map_data->character_data->down_i = assign_direction_data(map_array, map_data->character_data->curr_i, character_data->down_i, "down");
	map_data->character_data->left_i = assign_direction_data(map_array, map_data->character_data->curr_i, character_data->left_i, "left");
	map_data->character_data->right_i = assign_direction_data(map_array, map_data->character_data->curr_i, character_data->right_i, "right");
}