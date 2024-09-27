/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/27 18:14:16 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	verify_sprites(int chara, int loot, int door, int floor, int wall)
{
	int	valid_sprite;

	valid_sprite = 1;
	if (chara < 0 || loot < 0 || door < 0 || floor < 0 || wall < 0)
		valid_sprite = 0;
	close(chara);
	close(door);
	close(floor);
	close(loot);
	close(wall);
	return (valid_sprite);
}


void	collect_sprites(char **map_array, t_map *map_data)
{
	int	chara;
	int	loot;
	int	door;
	int	floor;
	int	wall;

	chara = open("sprites/xpm/chara.xpm", O_RDWR);
	door = open("sprites/xpm/door.xpm", O_RDWR);
	floor = open("sprites/xpm/floor.xpm", O_RDWR);
	loot = open("sprites/xpm/loot.xpm", O_RDWR);
	wall = open("sprites/xpm/wall.xpm", O_RDWR);
	if (!verify_sprites(chara, loot, door, floor, wall))
	{
		free_map(map_array);
		printf("ERROR: unable to access one or more sprites\n");
		exit(1);
	}
	map_data->character_img = "sprites/xpm/chara.xpm";
	map_data->door_img = "sprites/xpm/door.xpm";
	map_data->floor_img = "sprites/xpm/floor.xpm";
	map_data->loot_img = "sprites/xpm/loot.xpm";
	map_data->wall_img = "sprites/xpm/wall.xpm";
}
