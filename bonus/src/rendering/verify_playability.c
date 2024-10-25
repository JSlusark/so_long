/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_playability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/26 00:53:56 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	verify_playability(t_map *level)
{
	int		reachable_loot;
	int		x;
	int		y;

	reachable_loot = 0;
	allocate_map_dup(level);
	x = level->character_data->curr_i->x;
	y = level->character_data->curr_i->y;
	//check enemies function starts
	reach_enemies(y, x, level);
	if (enemy_was_found(level->map_dup))
	{
		ft_printf("Error: not all enemies can reach you, map is too easy!\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	//func ends
	free_map(level->map_dup);
	allocate_map_dup(level);
	//check loot function starts
	reachable_loot = collect_loot(y, x, &reachable_loot, level);
	if (reachable_loot != level->loot_n)
	{
		ft_printf("Error: Could not reach %d out of %d loot\n",
			level->loot_n - reachable_loot, level->loot_n);
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	//func ends
	//check exit function starts
	if (exit_was_found(level->map_dup))
	{
		ft_printf("Error: all loot can be collected but exit is blocked\n");
		free_map(level->map_dup);
		free_all_gamedata(level);
		exit(1);
	}
	//func ends
	free_map(level->map_dup);
}
