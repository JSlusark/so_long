/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 13:08:33 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	create_map_dup(char **map_dup, t_map *level)
{
	int	i;

	i = 0;
	if (!map_dup)
	{
		ft_printf("Error: Memory allocation failed for map copy\n");
		return (0);
	}
	while (i < level->height)
	{
		map_dup[i] = ft_strdup(level->map_array[i]);
		if (!map_dup[i])
		{
			ft_printf("Error: failed strdup on line %i\n", i);
			return (0);
		}
		i++;
	}
	map_dup[level->height] = NULL;
	return (1);
}

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

int	collect_loot(char **map_dup, int y, int x, int *reachable_loot, t_map *level)
{
	if (x < 0 || x >= level->height || y < 0 || y >= level->width)
		return (0);
	if (map_dup[x][y] == '1' || map_dup[x][y] == ' '
	|| ((*reachable_loot) != level->loot_n && map_dup[x][y] == 'E'))
	{
		if (map_dup[x][y] == 'E')
			map_dup[x][y] = ' ';
		return (0);
	}
	if (map_dup[x][y] == 'C')
		(*reachable_loot)++;
	map_dup[x][y] = ' ';
	collect_loot(map_dup, y, x - 1, reachable_loot, level);
	collect_loot(map_dup, y, x + 1, reachable_loot, level);
	collect_loot(map_dup, y - 1, x, reachable_loot, level);
	collect_loot(map_dup, y + 1, x, reachable_loot, level);
	if ((*reachable_loot) == level->loot_n && map_dup[x][y] == 'E')
		map_dup[x][y] = ' ';
	return (*reachable_loot);
}
void	verify_playability(t_map *level)
{
	int		reachable_loot;
	char	**map_dup;
	int		x;
	int		y;

	map_dup = malloc(sizeof(char *) * (level->height + 1));
	if (!create_map_dup(map_dup, level))
	{
		free_map(map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	reachable_loot = 0;
	x = level->character_data->curr_i->x;
	y = level->character_data->curr_i->y;
	reachable_loot = collect_loot(map_dup, y, x, &reachable_loot, level);
	if (reachable_loot != level->loot_n)
	{
		ft_printf("Error: Could not reach %d out of %d loot\n",
			level->loot_n - reachable_loot, level->loot_n);
		free_map(map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	if (exit_was_found(map_dup))
	{
		ft_printf("Error: all loot can be collected but exit is blocked\n");
		free_map(map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	free_map(map_dup);
}
