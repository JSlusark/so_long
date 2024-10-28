/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 18:22:06 by jslusark         ###   ########.fr       */
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

	chara = open("textures/xpm/chara.xpm", O_RDWR);
	door = open("textures/xpm/door.xpm", O_RDWR);
	floor = open("textures/xpm/floor.xpm", O_RDWR);
	loot = open("textures/xpm/loot.xpm", O_RDWR);
	wall = open("textures/xpm/wall.xpm", O_RDWR);
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
		ft_printf("Error: unable to access one or more sprites\n");
		exit(1);
	}
	level->character_img = "textures/xpm/chara.xpm";
	level->door_img = "textures/xpm/door.xpm";
	level->floor_img = "textures/xpm/floor.xpm";
	level->loot_img = "textures/xpm/loot.xpm";
	level->wall_img = "textures/xpm/wall.xpm";
	level->pixels = 64;
}
