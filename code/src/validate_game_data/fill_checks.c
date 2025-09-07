/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:36:59 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/08 00:27:20 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int exit_was_found(char **map_dup)
{
	int x;
	int y;

	x = 0;
	while (map_dup[x] != NULL)
	{
		y = 0;
		while (map_dup[x][y] != '\0')
		{
			if (map_dup[x][y] == 'E')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int enemy_was_found(char **map_dup)
{
	int x;
	int y;

	x = 0;
	while (map_dup[x] != NULL)
	{
		y = 0;
		while (map_dup[x][y] != '\0')
		{
			if (map_dup[x][y] == 'K')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int loot_was_found(char **map_dup)
{
	int x;
	int y;
	int loot_found;

	x = 0;
	loot_found = 0;
	while (map_dup[x] != NULL)
	{
		y = 0;
		while (map_dup[x][y] != '\0')
		{
			if (map_dup[x][y] == 'C')
				loot_found++;
			y++;
		}
		x++;
	}
	return (loot_found);
}

void reach_enemies(int y, int x, t_game *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return;
	if (level->map_dup[x][y] == '1' || level->map_dup[x][y] == ' ' || level->map_dup[x][y] == 'E')
		return;
	level->map_dup[x][y] = ' ';
	reach_enemies(y, x - 1, level);
	reach_enemies(y, x + 1, level);
	reach_enemies(y - 1, x, level);
	reach_enemies(y + 1, x, level);
}

int collect_loot(int y, int x, int *reachable_loot, t_game *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return (0);
	if (level->map_dup[x][y] == '1' || level->map_dup[x][y] == ' ' || ((*reachable_loot) != level->loot_n_remaining && level->map_dup[x][y] == 'E') || level->map_dup[x][y] == 'K')
	{
		if (level->map_dup[x][y] == 'E')
			level->map_dup[x][y] = ' ';
		return (0);
	}
	if (level->map_dup[x][y] == 'C')
		(*reachable_loot)++;
	level->map_dup[x][y] = ' ';
	collect_loot(y, x - 1, reachable_loot, level);
	collect_loot(y, x + 1, reachable_loot, level);
	collect_loot(y - 1, x, reachable_loot, level);
	collect_loot(y + 1, x, reachable_loot, level);
	if ((*reachable_loot) == level->loot_n_remaining && level->map_dup[x][y] == 'E')
		level->map_dup[x][y] = ' ';
	return (*reachable_loot);
}
