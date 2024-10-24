/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/24 20:16:57 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	verify_sprites(void)
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
	if (chara < 0 || loot < 0 || door < 0 || floor < 0 || wall < 0)
		return (0);
	close(chara);
	close(door);
	close(floor);
	close(loot);
	close(wall);
	return (1);
}

void	collect_sprites(char **map_array, t_map *level)
{
	if (!verify_sprites())
	{
		free_map(map_array);
		free(level);
		printf("Error: unable to access one or more sprites\n");
		exit(1);
	}
	level->character_img = "sprites/xpm/chara.xpm";
	level->door_img = "sprites/xpm/door.xpm";
	level->floor_img = "sprites/xpm/floor.xpm";
	level->loot_img = "sprites/xpm/loot.xpm";
	level->wall_img = "sprites/xpm/wall.xpm";
	level->pixels = 64;
}
