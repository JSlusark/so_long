/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/25 22:17:29 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	render_map(level->mini_libx.img, map_array, level, level->mini_libx);
	mlx_hook(level->mini_libx.session, 17, 0L, close_window, level);
	mlx_key_hook(level->mini_libx.session, key_hook, level);
	mlx_loop(level->mini_libx.game);
}

int	main(int argc, char **argv)
{
	t_map	*level;

	if (argc == 2)
	{
		level = malloc(sizeof(t_map));
		if (!level)
			exit(1);
		level->mini_libx.game = NULL;
		level->map_array = get_map(argv[1], level);
		verify_format(level->map_array, level);
		collect_sprites(level->map_array, level);
		allocate_chara_data(level);
		get_chara_position(level->map_array, level->character_data);
		verify_playability(level); // later
		launch_game(level->map_array, level);
		free_all_gamedata(level);
	}
	else
	{
		ft_printf("Error: ./so_long needs a map file to run!\n");
		exit(1);
	}
	return (0);
}
