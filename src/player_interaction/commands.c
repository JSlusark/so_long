/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:13:19 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/28 12:28:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit_update(t_map *level)
{
	if (level->loot_n == 0)
		level->activation = 1;
}

void	change_player_texture(int keycode, t_map	*level)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		level->character_img = "textures/xpm/up.xpm";
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		level->character_img = "textures/xpm/chara.xpm";
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		level->character_img = "textures/xpm/left.xpm";
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		level->character_img = "textures/xpm/right.xpm";
}

void	rerender_game(t_map *level)
{
	get_chara_position(level->map_array, level->character_data);
	render_map(level->mini_libx.img, level->map_array, level,
		level->mini_libx);
}

void	change_map(char *direction, char *character, t_map *level)
{
	if (*direction == '1' || (*direction == 'E' && level->loot_n != 0))
		return ;
	else if (*direction == 'K')
	{
		level->moves++;
		ft_printf("STEPS: %d\n", level->moves);
		ft_printf("SORRY, YOU DEAD.. TRY AGAIN MAYBE? :(\n");
		free_all_gamedata(level);
		exit(0);
	}
	else if (*direction == 'E' && level->loot_n == 0)
	{
		level->moves++;
		ft_printf("STEPS: %d\n", level->moves);
		ft_printf("YOU WON!\n");
		free_all_gamedata(level);
		exit(0);
	}
	else if (*direction == 'C')
		level->loot_n--;
	level->moves++;
	ft_printf("STEPS: %d\n", level->moves);
	*direction = *character;
	*character = '0';
	check_exit_update(level);
}

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
	}
	else
		return (0);
	change_player_texture(keycode, level);
	rerender_game(level);
	return (0);
}
