/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:13:19 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/26 18:05:15 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit_update(t_map *level)
{
	if(level->loot_n == 0)
		level->door_img = "textures/xpm/open.xpm";// here is when i put sprite!!! <--DO IMG CHECK in srite validation to be added!
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
		exit(1);
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
	check_exit_update(level); // checks EXIT is highlight
	level->moves++;
	ft_printf("STEPS: %d\n", level->moves);
	*direction = *character;
	*character = '0';
}

int	key_hook(int keycode, t_map	*level)
{
	// add function that gets keycode and chnagege chara img based on keycode
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		// check_exit_update(level);
		level->character_img = "textures/xpm/up.xpm";// here is when i put sprite!!!
		change_map(level->character_data->up_i->ptr,
		level->character_data->curr_i->ptr, level);
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		// check_exit_update(level);
		level->character_img = "textures/xpm/chara.xpm";// here is when i put sprite!!!
		change_map(level->character_data->down_i->ptr,
		level->character_data->curr_i->ptr, level);
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		// check_exit_update(level);
		level->character_img = "textures/xpm/left.xpm";// here is when i put sprite!!!
		change_map(level->character_data->left_i->ptr,
			level->character_data->curr_i->ptr, level);
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		// check_exit_update(level);
		level->character_img = "textures/xpm/right.xpm";// here is when i put sprite!!!
		change_map(level->character_data->right_i->ptr,
		level->character_data->curr_i->ptr, level);
	}
	else if (keycode == 65307 || keycode == Q_KEY)
	{
		free_all_gamedata(level);
		exit(0);
	}
	else
		return (0);
	get_chara_position(level->map_array, level->character_data);
	render_map(level->mini_libx.img, level->map_array, level,
		level->mini_libx);
	return (0);
}

int	close_window(t_map *level)
{
	free_all_gamedata(level);
	exit(0);
}
