/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:30 by jslusark          #+#    #+#             */
/*   Updated: 2025/08/13 11:55:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

static int verify_animation_sprites(void)
{
	int door_open;
	int open_1;
	int open_2;
	int open_3;
	int open_4;

	door_open = open("textures/xpm/open.xpm", O_RDWR);
	open_1 = open("textures/xpm/open_1.xpm", O_RDWR);
	open_2 = open("textures/xpm/open_2.xpm", O_RDWR);
	open_3 = open("textures/xpm/open_3.xpm", O_RDWR);
	open_4 = open("textures/xpm/open_4.xpm", O_RDWR);
	if (door_open < 0 || open_1 < 0 || open_2 < 0 || open_3 < 0 || open_4 < 0)
		return (0);
	close(door_open);
	close(open_1);
	close(open_2);
	close(open_3);
	close(open_4);
	return (1);
}

static int verify_bonus_sprites(void)
{
	int enemy;
	int left;
	int right;
	int up;

	enemy = open("textures/xpm/enemy.xpm", O_RDWR);
	left = open("textures/xpm/left.xpm", O_RDWR);
	right = open("textures/xpm/right.xpm", O_RDWR);
	up = open("textures/xpm/up.xpm", O_RDWR);
	if (enemy < 0 || left < 0 || right < 0 || up < 0)
		return (0);
	close(enemy);
	close(left);
	close(right);
	close(up);
	return (1);
}

static int verify_sprites(void)
{
	int chara;
	int loot;
	int door;
	int floor;
	int wall;

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

void collect_sprites(char **map_array, t_game *level)
{
	if (!verify_sprites() || !verify_bonus_sprites() || !verify_animation_sprites())
	{
		free_map(map_array);
		free(level);
		ft_printf("Error: unable to access one or more sprites\n");
		exit(1);
	}
	level->char_frame_0 = "textures/xpm/down_0.xpm";
	level->char_frame_1 = "textures/xpm/down_1.xpm";
	level->char_frame_2 = "textures/xpm/down_2.xpm";
	level->character_img = "textures/xpm/chara.xpm";
	level->door_img = "textures/xpm/door.xpm";
	level->floor_img = "textures/xpm/floor.xpm";
	level->loot_img = "textures/xpm/loot.xpm";
	level->wall_img = "textures/xpm/wall.xpm";
	level->enemy_img = "textures/xpm/enemy.xpm";
	level->pixels = 64;
}
