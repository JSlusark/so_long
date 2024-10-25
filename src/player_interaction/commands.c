/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:13:19 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 11:18:12 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_hook(int keycode, t_map	*level)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		change_map(level->character_data->up_i->ptr,
			level->character_data->curr_i->ptr, level);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		change_map(level->character_data->down_i->ptr,
			level->character_data->curr_i->ptr, level);
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		change_map(level->character_data->left_i->ptr,
			level->character_data->curr_i->ptr, level);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		change_map(level->character_data->right_i->ptr,
			level->character_data->curr_i->ptr, level);
	else if (keycode == 65307 || keycode == Q_KEY)
	{
		free_all_gamedata(level);
		exit(0);
		printf("Clicked exit!\n");
	}
	else
		return (0);
	get_chara_position(level->map_array, level);
	render_map(level->mini_libx.img, level->map_array, level,
		level->mini_libx.game, level->mini_libx.session);
	return (0);
}

int	close_window(t_map *level)
{
	free_all_gamedata(level);
	exit(0);
}
