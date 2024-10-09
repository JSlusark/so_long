/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/09 14:32:25 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static	void launch_game(char **map_array, t_map *level)
{

	void	*game;
	void	*session;
	void	*img;

	printf("launching game..\n");
	printf("first line map_array %s..\n", map_array[0]);
	printf("character file path %s\n", level->character_img);
	printf("w: %d h: %d\n", level->width, level->height);
	printf("tile_pixel: %d\n", level->pixels);

	img = NULL;
	game = mlx_init();
	if (!game)
		exit(1);
	session = mlx_new_window(game, (level->pixels * level->width), (level->pixels * level->height), "Hello world!");
	if (!session)
	 {
		free(game),
		exit(1);
	}
	render_map(img, map_array, level, game, session);
	mlx_loop(game);
	// free(session);
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
		// init_chara_data(map_array, &map_data); // <---- check if it goes here or better elsewhere and if needed
		printf("Location: main.c h:%d w:%d\n", map_data->height, map_data->width);
		// add function to see if map is bigger than screen res ❗❗❗
		launch_game(map_array, map_data);
		free(map_data); // IMPORTANT!!
		free_map(map_array); // IMPORTANT!!
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
