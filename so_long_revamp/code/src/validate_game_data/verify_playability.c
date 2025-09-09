/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/08 00:27:20 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void enemy_check(t_game *level, int y, int x)
{
	reach_enemies(y, x, level);
	if (enemy_was_found(level->map_dup))
	{
		ft_printf("Error: not all enemies can reach you, map is too easy!\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	free_map(level->map_dup);
	allocate_map_dup(level);
}

void exit_check(t_game *level)
{
	if (exit_was_found(level->map_dup))
	{
		ft_printf("Error: all loot can be collected but exit is blocked\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
}

void verify_playability(t_game *level)
{
	int reachable_loot;
	int x;
	int y;

	reachable_loot = 0;
	allocate_map_dup(level);
	x = level->character_data->curr_i->x;
	y = level->character_data->curr_i->y;
	enemy_check(level, y, x);
	reachable_loot = collect_loot(y, x, &reachable_loot, level);
	if (reachable_loot != level->loot_n_remaining)
	{
		ft_printf("Error: Could not reach %d out of %d loot\n",
				  level->loot_n_remaining - reachable_loot, level->loot_n_remaining);
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	exit_check(level);
	// free_map(level->map_dup); // TODO: free at end!!
}
