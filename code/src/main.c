/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2025/09/09 16:23:33 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void launch_game(char **map_array, t_game *level)
{
	audio_init();
	level->mini_libx.game = mlx_init();
	if (!level->mini_libx.game)
	{
		free_all_gamedata(level);
		exit(1);
	}
	// printf("lanch\n");

	level->mini_libx.session = mlx_new_window(level->mini_libx.game,
											  (level->pixels * level->width), (level->pixels * level->height),
											  "SO_LONG");
	if (!level->mini_libx.session)
	{
		free_all_gamedata(level);
		exit(1);
	}
	int w = 5;
	int h = 5;
	
	level->heart_icon = mlx_xpm_file_to_image(level->mini_libx.game,
											  "assets/xpm/heart_icon.xpm", &w, &h);
	// show loading page with start
	start_music("assets/mp3/level_music.mp3", 0.25f);
	render_map(level->mini_libx.img, map_array, level, level->mini_libx);
	mlx_hook(level->mini_libx.session, 17, 0L, close_window, level);
	mlx_key_hook(level->mini_libx.session, key_hook, level);
	mlx_loop_hook(level->mini_libx.game, animation, level);
	mlx_loop(level->mini_libx.game);
}

void load_map(t_level *levels, t_game *game)
{
	// ft_printf("%s", game->map_dup[1]);
	// if (game->death)
	// {
	if (game->lives == 0)
	{
		stop_music();
		stop_sfx();
		ft_printf("💀 You lost all your lives \n🍀 Maybe try again?");
		exit(0);
	}
	// game->death = false;
	// ft_printf("you lost! Lives remaining: %d\n", game->lives);
	// load lost life img
	// }
	// else
	// {
	game->level_i++; // if lives are still there it means that we go next level
	// }
	game->exit_active = 0;
	if (!levels[game->level_i].level_path)
	{
		// game->end_game = true; // may be useful for the start/endgame section
		ft_printf("🥳🎉You've won the game!🎉🥳");
		stop_music();
		exit(0); // go back to start game
	}
	game->level_file = game->all_levels[game->level_i].level_path;
	game->start_level_screen = game->all_levels[game->level_i].start_level_screen;
	game->map_array = get_map(game->level_file, game);
	// instead verify all games before the gane starts so i just call the old/new map
	// while levels is not null do a loop and chek all the maps then call load map
	verify_format(game->map_array, game);
	allocate_chara_data(game);
	get_chara_position(game->map_array, game->character_data);
	verify_playability(game);
	create_map_dup(game->map_dup, game);
	game->loot_n = game->loot_n_remaining;
	// printf("total loot_n_remaining %d\n", game->loot_n_remaining);
	// printf("total loot_n %d\n", game->loot_n);
}

int main()
{
	t_game *game;

	t_level all_levels[] = {
		{"map/01.ber", "assets/loading/loading01.xpm"},
		{"map/02.ber", "assets/loading/loading02.xpm"},
		{"map/03.ber", "assets/loading/loading03.xpm"},
		{"map/04.ber", "assets/loading/loading04.xpm"},
		{"map/05.ber", "assets/loading/loading05.xpm"},
		{NULL, NULL} // sentinel to mark end
	};
	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->mini_libx.game = NULL;
	game->all_levels = malloc(sizeof(all_levels));
	if (!game->all_levels)
		exit(1);
	memcpy(game->all_levels, all_levels, sizeof(all_levels));
	game->level_i = -1;
	// ft_memcpy(level->level_array, temp_levels, sizeof(temp_levels));
	// level->level_i = -1;
	game->lives = 3;
	game->death = false;
	collect_sprites(game->map_array, game); // collect creatives
	audio_init();
	load_map(game->all_levels, game);
	launch_game(game->map_array, game);
	// free_all_gamedata(level);
	return (0);
}
