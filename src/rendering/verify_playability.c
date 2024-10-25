/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 18:31:10 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	exit_was_found(char **map_dup)
{
	int	x;
	int	y;

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

int	collect_loot(int y, int x, int *reachable_loot, t_map *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return (0);
	if (level->map_dup[x][y] == '1' || level->map_dup[x][y] == ' '
	|| ((*reachable_loot) != level->loot_n && level->map_dup[x][y] == 'E'))
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
	if ((*reachable_loot) == level->loot_n && level->map_dup[x][y] == 'E')
		level->map_dup[x][y] = ' ';
	return (*reachable_loot);
}

void	verify_playability(t_map *level)
{
	int		reachable_loot;
	int		x;
	int		y;

	allocate_map_dup(level);
	reachable_loot = 0;
	x = level->character_data->curr_i->x;
	y = level->character_data->curr_i->y;
	reachable_loot = collect_loot(y, x, &reachable_loot, level);
	if (reachable_loot != level->loot_n)
	{
		ft_printf("Error: Could not reach %d out of %d loot\n",
			level->loot_n - reachable_loot, level->loot_n);
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	if (exit_was_found(level->map_dup))
	{
		ft_printf("Error: all loot can be collected but exit is blocked\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	free_map(level->map_dup);
}
