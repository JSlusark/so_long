/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/26 00:34:30 by jslusark         ###   ########.fr       */
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

int	enemy_was_found(char **map_dup)
{
	int	x;
	int	y;

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

int	loot_was_found(char **map_dup)
{
	int	x;
	int	y;
	int	loot_found;

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

void	reach_enemies(int y, int x, t_map *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return ;
	if (level->map_dup[x][y] == '1' || level->map_dup[x][y] == ' '
		|| level->map_dup[x][y] == 'E')
		return ;
	level->map_dup[x][y] = ' ';
	reach_enemies(y, x - 1, level);
	reach_enemies(y, x + 1, level);
	reach_enemies(y - 1, x, level);
	reach_enemies(y + 1, x, level);
}

int	collect_loot(int y, int x, int *reachable_loot, t_map *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return (0);
	if (level->map_dup[x][y] == '1' || level->map_dup[x][y] == ' '
	|| ((*reachable_loot) != level->loot_n && level->map_dup[x][y] == 'E')
	|| level->map_dup[x][y] == 'K')
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

	reachable_loot = 0;
	allocate_map_dup(level);
	x = level->character_data->curr_i->x;
	y = level->character_data->curr_i->y;
	print_map(level->map_array); //remove
	printf("\n");
	reach_enemies(y, x, level);
	// print_map(level->map_dup); //remove
	if (enemy_was_found(level->map_dup))
	{
		ft_printf("Error: not all enemies can reach you, map is too easy!\n");
		print_map(level->map_dup); //remove
		printf("\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	print_map(level->map_dup); // remove
	printf("\n");
	free_map(level->map_dup);
	// create_map_dup(level->map_dup, level);
	allocate_map_dup(level);
	print_map(level->map_dup); // remove
	printf("\n");
	reachable_loot = collect_loot(y, x, &reachable_loot, level);
	if (reachable_loot != level->loot_n)
	{
		printf("Error: Could not reach %d out of %d loot\n",// FT!!!
			level->loot_n - reachable_loot, level->loot_n);
		print_map(level->map_dup); // remove
		printf("\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	print_map(level->map_dup); // remove
	if (exit_was_found(level->map_dup))
	{
		ft_printf("Error: all loot can be collected but exit is blocked\n");
		print_map(level->map_dup); //remove
		printf("\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	print_map(level->map_dup); //remove
	printf("\n");
	free_map(level->map_dup);
}
