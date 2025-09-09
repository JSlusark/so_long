/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:13:19 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/09 16:52:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void check_exit_update(t_game *level)
{
	if (level->loot_n_remaining == 0)
		level->exit_active = 1;
	if (level->exit_active)
		play_sfx("assets/audio/bubbles.wav", 0.8f, false);
}

void change_player_texture(int keycode, t_game *level)
{
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		level->character_img = "assets/xpm/up.xpm";
		level->char_frame_0 = "assets/xpm/up_0.xpm";
		level->char_frame_1 = "assets/xpm/up_1.xpm";
		level->char_frame_2 = "assets/xpm/up_2.xpm";
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		level->character_img = "assets/xpm/chara.xpm";
		level->char_frame_0 = "assets/xpm/down_0.xpm";
		level->char_frame_1 = "assets/xpm/down_1.xpm";
		level->char_frame_2 = "assets/xpm/down_2.xpm";
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		level->character_img = "assets/xpm/left.xpm";
		level->char_frame_0 = "assets/xpm/left_0.xpm";
		level->char_frame_1 = "assets/xpm/left_1.xpm";
		level->char_frame_2 = "assets/xpm/left_2.xpm";
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		level->character_img = "assets/xpm/right.xpm";
		level->char_frame_0 = "assets/xpm/right_0.xpm";
		level->char_frame_1 = "assets/xpm/right_1.xpm";
		level->char_frame_2 = "assets/xpm/right_2.xpm";
	}
}

void reset_map(char **map_dup, t_game *game)
{
	stop_music();
	stop_sfx();
	start_music("assets/audio/level_music.wav", 0.25f);
	int i = 0;
	// printf("Map_array and data before reset\n");
	// print_map(game->map_array);
	// print_level_data(game);
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
	game->door_img = "assets/xpm/door.xpm";
	game->character_img = "assets/xpm/chara.xpm";
	// printf("Map_array and data after reset\n");
	// print_map(game->map_array);
	// print_level_data(game);
}

void change_map(char *direction, char *character, t_game *game)
{
	if (*direction == '1' || (*direction == 'E' && game->loot_n_remaining != 0))
		return;
	play_sfx("assets/audio/walk.wav", 0.6f, true);
	if (*direction == 'K')
	{
		game->moves++;
		ft_printf("🐾 STEPS: %d\n", game->moves);
		// ft_printf("SORRY, YOU DEAD.. TRY AGAIN MAYBE? :(\n");
		game->lives--;
		play_sfx("assets/audio/damage.wav", 0.6f, true);
		// game->moves = 0;
		game->exit_active = 0;
		if (game->lives == 0)
		{
			// stop_music();
			// play_sfx("assets/audio/you_lose.wav", 0.6f);
			ft_printf("💀 You lost all your lives \n🍀 Maybe try again?");
			stop_music();
			stop_sfx();
			exit(0);
		}
		// game->death = false;
		// stop_music();
		ft_printf("💔You lost! Lives remaining: %d\n", game->lives);
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
		ft_printf("🐾 STEPS: %d\n", game->moves);
		// free_all_gamedata(level);
		mlx_destroy_window(game->mini_libx.game, game->mini_libx.session);

		load_map(game->all_levels, game);
		stop_music();
		stop_sfx();
		start_music("assets/audio/level_music.wav", 0.25f);

		game->mini_libx.session = mlx_new_window(game->mini_libx.game,
												 (game->pixels * game->width), (game->pixels * game->height),
												 "SO_LONG");
		mlx_key_hook(game->mini_libx.session, key_hook, game);
		// game->death = true;
		game->exit_active = false;
		game->door_img = "assets/xpm/door.xpm";
		game->character_img = "assets/xpm/chara.xpm";

		ft_printf("🔥You won level %d!🔥\n", game->level_i);
		return;
		//
		// exit(0);
	}
	else if (*direction == 'C')
	{
		play_sfx("assets/audio/collect.wav", 0.6f, true);
		game->loot_n_remaining--;
	}
	game->moves++;
	ft_printf("🐾 STEPS: %d\n", game->moves);
	*direction = *character;
	*character = '0';
	check_exit_update(game);
}

int key_hook(int keycode, t_game *level)
{
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		// play_sfx("assets/audio/walk.wav", 0.6f);
		change_map(level->character_data->up_i->ptr,
				   level->character_data->curr_i->ptr, level);
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		// play_sfx("assets/audio/walk.wav", 0.6f);
		change_map(level->character_data->down_i->ptr,
				   level->character_data->curr_i->ptr, level);
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		// play_sfx("assets/audio/walk.wav", 0.6f);
		change_map(level->character_data->left_i->ptr,
				   level->character_data->curr_i->ptr, level);
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		// play_sfx("assets/audio/walk.wav", 0.6f);
		change_map(level->character_data->right_i->ptr,
				   level->character_data->curr_i->ptr, level);
	}
	else if (keycode == ESC_KEY || keycode == Q_KEY)
	{
		stop_music();
		stop_sfx();
		level->exit_active = false;
		free_all_gamedata(level);
		exit(0);
	}
	else
		return (0);

	change_player_texture(keycode, level);
	rerender_game(level);
	return (0);
}
