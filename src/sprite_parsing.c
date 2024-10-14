/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/14 16:31:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// looping to thorugh the array so that when we find the character we will create its own struct (t_characrter) that stores information about itself and the tiles surrounding it
// this info can be used to update the map array when the character moves and interacts with the map
// FUNCTIONS WERE JUST DRAFTED WHILE THINKING ABOUT THE PROCESS/LOGIC, MAKE SURE LOGIC WORKS AND MAKES SENSE

void	find_direction_coords(t_coord *character_coords, char *direction, int x, int y) // func can be used once wit ahh assets
{
	// USE MY OWN STRCMP!!!!
	if (strcmp(direction, "up") == 0) // i do not need to hadle in the even coors are outside the map as chara will alsways be framed by unpassable walls
	{
		x = character_coords->x - 1; // WE MOVE UP of one row of chara, therefore x - 1
		y = character_coords->y; // we are still in the same col (y axis) of chara
	}
	if (strcmp(direction, "down") == 0)
	{
		x = character_coords->x + 1; // WE MOVE DOWN of one row of chara, therefore x + 1
		y = character_coords->y; // we are still in the same col (y axis) of chara
	}
	if (strcmp(direction, "left") == 0)
	{
		x = character_coords->y - 1;  // WE MOVE LEFT thorugh y axis of chara therefore y - 1
		y = character_coords->x; // we are still in the same row (x axis) of chara
	}
	if (strcmp(direction, "right") == 0)
	{
		x = character_coords->y + 1;  // WE MOVE RIGHT thorugh y axis of chara therefore y + 1
		y = character_coords->x; // we are still in the same row (x axis) of chara
	}
}

void	assign_direction_data(char **map_array, t_coord *character_coords, t_coord *direction_coords, char *direction) // func can be used once wit ahh assets
{
	int row = 0;
	int col = 0;

	direction_coords = malloc(sizeof(t_coord)); // will be first up down left right stuct
	if(!direction_coords)
	{
		printf("%s coords mallo failed\n", direction);
		// error;
	}
	find_direction_coords(character_coords, direction, row, col); // func can be used once wit ahh assets
	if(direction_coords->x < 0 || direction_coords->y < 0 )
	{
		printf("ERROR: character should be surrounded by elements\n");// exit
		printf("-----> Direction %s, array[%d][%d] and outside of map index\n", direction, row, col);
		// EXIT?!
	}
	else
	{
		direction_coords->ptr = &map_array[row][col];
		direction_coords->x = row;
		direction_coords->y = col;
	}
	// return(direction_coords);
}

t_sprite	*assign_character_data(char **map_array, int r, int c)
{
	t_sprite	*character_data;

	character_data = malloc(sizeof(t_sprite));
	if (!character_data) // Always check for successful malloc
		return (NULL);
	//assigning chara data
	character_data->ptr = &map_array[r][c]; // we have the letter and also address of sprite
	character_data->moves = 0; //needed only for chara
	character_data->loot_collected = 0; //needed only for chara
	character_data->curr_i = malloc(sizeof(t_coord));
	if (!character_data->curr_i)
	{
		free(character_data); // free character data in adance check if double leak
		return (NULL); // If malloc fails, avoid memory leaks
	}
	character_data->curr_i->ptr = &map_array[r][c];
	character_data->curr_i->x = r;
	character_data->curr_i->y = c;
	return(character_data);
}

void	init_chara_data(char **map_array, t_map *map_data) // could be used to update array after char movement
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (map_array[r] != NULL)
	{
		c = 0;
		while (map_array[r][c] != '\0')
		{
			if(map_array[r][c] == 'P')
				map_data->character_data = assign_character_data(map_array, r, c);
			c++;
		}
		r++;
	}

	//should i free everything here
	// if (!map_data->character_data)
	// {
	// 	free(map_data);
	// 	exit(1);
	// }
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->up_i, "up");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->down_i, "down");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->left_i, "left");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->right_i, "right");



	// printf("   %d    \n", map_data->character_data->up_i->x); // why is this giving me sigv? i also want to make sure that i can print the ptr of every
	// printf("%s %s %s \n", );

}
