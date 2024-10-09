/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/09 11:22:26 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void launch_game(char **map_array, t_map *level)
{

	void	*game;
	void	*window;
	// void	wall;
	// void	floor;
	// void	exit;
	// void	chara;
	// void	loot;

	printf("launching game..\n");
	printf("first line map_array %s..\n", map_array[0]);
	printf("character file path %s\n", level->character_img);
	printf("w: %d h: %d\n", level->width, level->height);


	game = mlx_init();
	window = mlx_new_window(game, (64 * level->width), (64 * level->height), "Hello world!");
	mlx_loop(game);
	// // printf("character file path %d\n", map_data->character_img);
	// game = mlx_init();
	// window = mlx_new_window(game, 32, 32, "SO_LONG");
	// if (!window)
	//  {
	// 	free(game),
	// 	exit(1);
	// }
	// if (!game)
	// 	exit(1);
	// // // render map
	// // // at key event count move and update map array and update sprite parsing
	// // // re-render?
	// mlx_loop(game);
	// free(game);


}

int	main(int argc, char **argv)
{
	char	**map_array;
	t_map	*map_data;
	printf("NOTE: PLEASE REMEMBER TO REPLACE WITH YOUR CORRECTED PRINTF\n");
	if (argc == 2)
	{
		map_data = malloc(sizeof(t_map));
		map_array = get_map(argv[1], map_data);
		collect_sprites(map_array, map_data);
		// init_chara_data(map_array, &map_data);
	printf("Location: main.c h:%d w:%d\n", map_data->height, map_data->width);
		launch_game(map_array, map_data);
		free(map_data);
		free_map(map_array); // IMPORTANT!!
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
