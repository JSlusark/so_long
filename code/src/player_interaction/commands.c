/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:13:19 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/08 01:01:59 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void check_exit_update(t_game *level)
{
	if (level->loot_n_remaining == 0)
		level->exit_active = 1;
}

void change_player_texture(int keycode, t_game *level)
{
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		level->character_img = "textures/xpm/up.xpm";
		level->char_frame_0 = "textures/xpm/up_0.xpm";
		level->char_frame_1 = "textures/xpm/up_1.xpm";
		level->char_frame_2 = "textures/xpm/up_2.xpm";
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		level->character_img = "textures/xpm/chara.xpm";
		level->char_frame_0 = "textures/xpm/down_0.xpm";
		level->char_frame_1 = "textures/xpm/down_1.xpm";
		level->char_frame_2 = "textures/xpm/down_2.xpm";
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		level->character_img = "textures/xpm/left.xpm";
		level->char_frame_0 = "textures/xpm/left_0.xpm";
		level->char_frame_1 = "textures/xpm/left_1.xpm";
		level->char_frame_2 = "textures/xpm/left_2.xpm";
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		level->character_img = "textures/xpm/right.xpm";
		level->char_frame_0 = "textures/xpm/right_0.xpm";
		level->char_frame_1 = "textures/xpm/right_1.xpm";
		level->char_frame_2 = "textures/xpm/right_2.xpm";
	}
}

void reset_map(char **map_dup, t_game *game)
{

	int i = 0;
	printf("Map_array and data before reset\n");
	print_map(game->map_array);
	print_level_data(game);
	while (game->map_array[i])
	{
		// if string compoare fails
		ft_strlcpy(game->map_array[i], map_dup[i], game->width + 1);
		i++;
	};
	// game->death = true;
	game->exit_active = false;
	game->loot_n_remaining = game->loot_n; // change
	game->moves = 0;					   // change
	game->door_img = "textures/xpm/door.xpm";
	game->character_img = "textures/xpm/chara.xpm";
	printf("Map_array and data after reset\n");
	print_map(game->map_array);
	print_level_data(game);
}

void change_map(char *direction, char *character, t_game *game)
{
	if (*direction == '1' || (*direction == 'E' && game->loot_n_remaining != 0))
		return;
	else if (*direction == 'K')
	{
		game->moves++;
		ft_printf("STEPS: %d\n", game->moves);
		// ft_printf("SORRY, YOU DEAD.. TRY AGAIN MAYBE? :(\n");
		game->lives--;
		// game->moves = 0;
		game->exit_active = 0;
		// game->death = true;
		// mlx_destroy_window(game->mini_libx.game, game->mini_libx.session);
		// load_map(game->all_levels, level); // as no need to change the level here
		// 									// free_all_gamedata(level);
		// 									// exit(0);
		if (game->lives == 0)
		{
			ft_printf("you lost all your lives :( you dead");
			exit(0);
		}
		// game->death = false;
		ft_printf("you lost! Lives remaining: %d\n", game->lives);
		// free_map(game->map_array);
		// if (create_map_dup(game->map_dup, game))
		// {
		reset_map(game->map_dup, game);
		rerender_game(game);
		return;
		// }
	}
	else if (*direction == 'E' && game->loot_n_remaining == 0)
	{
		game->moves++;
		ft_printf("STEPS: %d\n", game->moves);
		// ft_printf("YOU WON!\n");
		// free_all_gamedata(level);
		mlx_destroy_window(game->mini_libx.game, game->mini_libx.session);

		load_map(game->all_levels, game);
		game->mini_libx.session = mlx_new_window(game->mini_libx.game,
												 (game->pixels * game->width), (game->pixels * game->height),
												 "SO_LONG");
		mlx_key_hook(game->mini_libx.session, key_hook, game);
		// game->death = true;
		game->exit_active = false;
		game->door_img = "textures/xpm/door.xpm";
		game->character_img = "textures/xpm/chara.xpm";

		ft_printf("Level %d won!\n", game->level_i);
		return;
		//
		// exit(0);
	}
	else if (*direction == 'C')
	{
		game->loot_n_remaining--;
	}
	game->moves++;
	ft_printf("STEPS: %d\n", game->moves);
	*direction = *character;
	*character = '0';
	check_exit_update(game);
}

int key_hook(int keycode, t_game *level)
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
