/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2025/08/12 16:04:10 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void launch_game(char **map_array, t_map *level)
{
	level->mini_libx.game = mlx_init();
	if (!level->mini_libx.game)
	{
		free_all_gamedata(level);
		exit(1);
	}
	printf("lanch\n");
	level->mini_libx.session = mlx_new_window(level->mini_libx.game,
											  (level->pixels * level->width), (level->pixels * level->height),
											  "SO_LONG");
	if (!level->mini_libx.session)
	{
		free_all_gamedata(level);
		exit(1);
	}
	render_map(level->mini_libx.img, map_array, level, level->mini_libx);
	mlx_hook(level->mini_libx.session, 17, 0L, close_window, level);
	mlx_key_hook(level->mini_libx.session, key_hook, level);
	mlx_loop_hook(level->mini_libx.game, animation, level);
	mlx_loop(level->mini_libx.game);
}

void load_map(char **levels, t_map *level)
{
	level->curr_map++;
	if (!levels[level->curr_map])
	{
		// level->end_game = true;
		ft_printf("you've won!");
		exit(0);
	}
	level->map_array = get_map(levels[level->curr_map], level);
	verify_format(level->map_array, level);
	collect_sprites(level->map_array, level);
	allocate_chara_data(level);
	get_chara_position(level->map_array, level->character_data);
	verify_playability(level);
	// level->mini_libx.session = mlx_new_window(level->mini_libx.game,
	// 										  (level->pixels * level->width), (level->pixels * level->height),
	// 										  "SO_LONG");
	// level->activation = 0;
	// printf("%s", level->map_array[0]);
}

int main()
{
	t_map *level;

	char *temp_levels[] =
		{
			"map/01.ber",
			"map/02.ber",
			// "map/03.ber",
			// "map/04.ber",
			// "map/05.ber",
			NULL};
	level = malloc(sizeof(t_map));
	if (!level)
		exit(1);
	level->mini_libx.game = NULL;
	ft_memcpy(level->level_array, temp_levels, sizeof(temp_levels));
	level->curr_map = -1;
	load_map(level->level_array, level);
	launch_game(level->map_array, level);
	// free_all_gamedata(level);
	return (0);
}
