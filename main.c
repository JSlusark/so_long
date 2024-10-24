/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/24 18:31:45 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (keycode == 65307 || keycode == Q_KEY) // <------this does not work?
	{
		free_all_gamedata(level);
		exit(0);
		printf("Clicked exit!\n");
	}
	else
		return (0);
	free_sprite(level->character_data);
	init_chara_data(level->map_array, level);
	render_map(level->mini_libx.img, level->map_array, level,
		level->mini_libx.game, level->mini_libx.session);
	return (0);
}

int	close_window(t_map *level)
{
	free_all_gamedata(level);
	exit(0);
}

static void	launch_game(char **map_array, t_map *level)
{
	level->mini_libx.game = mlx_init();
	if (!level->mini_libx.game)
		exit(1);
	level->mini_libx.session = mlx_new_window(level->mini_libx.game,
			(level->pixels * level->width), (level->pixels * level->height),
			"SO_LONG");
	if (!level->mini_libx.session)
	{
		free(level->mini_libx.game),
		exit(1);
	}
	render_map(level->mini_libx.img, map_array, level,
		level->mini_libx.game, level->mini_libx.session);
	mlx_hook(level->mini_libx.session, 17, 0L, close_window, level);
	mlx_key_hook(level->mini_libx.session, key_hook, level);
	mlx_loop(level->mini_libx.game);
}

int	main(int argc, char **argv)
{
	t_map	*level;

	printf("NOTE: PLEASE REMEMBER TO REPLACE WITH YOUR CORRECTED PRINTF\n");
	if (argc == 2)
	{
		level = malloc(sizeof(t_map));
		level->map_array = get_map(argv[1], level);
		verify_format(level->map_array, level);
		collect_sprites(level->map_array, level);
		init_chara_data(level->map_array, level);
		verify_playability(level);
		launch_game(level->map_array, level);
		free_all_gamedata(level);
	}
	else
	{
		printf("Error: ./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
