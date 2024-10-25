/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:26:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 12:41:11 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	allocate_chara_data(t_map *level)
{
	level->character_data = malloc(sizeof(t_sprite));
	if (!level->character_data)
	{
		free(level);
		exit(1);
	}
	level->character_data->curr_i = malloc(sizeof(t_coord));
	level->character_data->up_i = malloc(sizeof(t_coord));
	level->character_data->down_i = malloc(sizeof(t_coord));
	level->character_data->left_i = malloc(sizeof(t_coord));
	level->character_data->right_i = malloc(sizeof(t_coord));
	if (!level->character_data->curr_i || !level->character_data->up_i
		|| !level->character_data->down_i || !level->character_data->left_i
		|| !level->character_data->right_i)
	{
		free_all_gamedata(level);
		exit(1);
	}
}
