/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/14 19:18:10 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_chara_data(t_sprite *c)
{
	printf("symbol: %c\n", c->ptr);
	printf("moves: %d\n", c->moves);
	printf("loot collected: %d\n", c->loot_collected);
	printf("position map_array[%d][%d]\n", c->curr_i->x, c->curr_i->y);

	printf("CHARACTER POSITION AND SURROUNDINGS:\n");
	printf(" %c\n",c->up_i->ptr);
	printf("%c%c%c\n",c->left_i->ptr, c->ptr, c->right_i->ptr);
	printf(" %c \n",c->down_i->ptr);

	printf("symbol: %c\n", c->up_i->ptr);
	printf("position map_array[%d][%d]\n", c->up_i->x, c->up_i->y);

}

// looping to thorugh the array so that when we find the character we will create its own struct (t_characrter) that stores information about itself and the tiles surrounding it
// this info can be used to update the map array when the character moves and interacts with the map
// FUNCTIONS WERE JUST DRAFTED WHILE THINKING ABOUT THE PROCESS/LOGIC, MAKE SURE LOGIC WORKS AND MAKES SENSE

void find_direction_coords(t_coord *character_coords, char *direction, int x, int y)
{
    // Use MY strcmp to compare strings
    if (strcmp(direction, "up") == 0)
    {
        x = character_coords->x - 1; // Update x by reference
        y = character_coords->y;
    }
    else if (strcmp(direction, "down") == 0)
    {
        x = character_coords->x + 1;
        y = character_coords->y;
    }
    else if (strcmp(direction, "left") == 0)
    {
        x = character_coords->x;
        y = character_coords->y - 1;
    }
    else if (strcmp(direction, "right") == 0)
    {
        x = character_coords->x;
        y = character_coords->y + 1;
    }
}

void	assign_direction_data(char **map_array, t_coord *character_coords, t_coord *direction_coords, char *direction) // func can
{
	// find_direction_coords(character_coords, direction, direction_coords->x, direction_coords->y); // func can be used once wit ahh assets
	// if(direction_coords->x < 0 || direction_coords->y < 0 )
	// {
	// 	printf("ERROR: character should be surrounded by elements\n");// exit
	// 	printf("-----> Direction %s, array[%d][%d] and outside of map index\n", direction, direction_coords->x,direction_coords->y);
	// 	// EXIT?!
	// }
	    // Use MY strcmp to compare strings
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
	direction_coords->ptr = map_array[direction_coords->x][direction_coords->y];
	// printf("DIR COORDS: %c\n\n\n\n", direction_coords->ptr);
}

t_sprite	*assign_character_data(char **map_array, int r, int c)
{
	t_sprite	*character_data;

	character_data = malloc(sizeof(t_sprite));
	if (!character_data) // Always check for successful malloc
		return (NULL);
	character_data->ptr = map_array[r][c]; // we have the letter and also address of sprite
	character_data->moves = 0; //needed only for chara
	character_data->loot_collected = 0; //needed only for chara
	character_data->curr_i = malloc(sizeof(t_coord));
	if (!character_data->curr_i)
	{
		free(character_data); // free character data in adance check if double leak
		return (NULL); // If malloc fails, avoid memory leaks
	}
	character_data->curr_i->ptr = map_array[r][c];
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
	map_data->character_data->up_i = malloc(sizeof(t_coord));
	map_data->character_data->down_i = malloc(sizeof(t_coord));
	map_data->character_data->left_i = malloc(sizeof(t_coord));
	map_data->character_data->right_i = malloc(sizeof(t_coord));
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->up_i, "up");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->down_i, "down");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->left_i, "left");
	assign_direction_data(map_array, map_data->character_data->curr_i, map_data->character_data->right_i, "right");
	print_chara_data(map_data->character_data); // this stays TRY IN PALGAME
	printf(" UP: %c\n", map_data->character_data->up_i->ptr);
}
