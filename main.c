/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/14 14:58:18 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, int nulls)
{
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		// Move character up
		printf("Moving up!\n");
		// Your logic to move the character up
	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		// Move character down
		printf("Moving down!\n");
		// Your logic to move the character down
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		// Move character left
		printf("Moving left!\n");
		// Your logic to move the character left
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		// Move character right
		printf("Moving right!\n");
		// Your logic to move the character right
	}
	else if (keycode == 65307 || keycode == Q_KEY) // <------this does not work
	{
			exit(0);
		// close_window(lib);
		// mlx_destroy_window(lib.game, lib.session);
		printf("Clicked exit!\n");
	}
	// printf("keycode: %d, %d\n", keycode, nulls);
	// return (0);
	printf("keycode: %d, %d", keycode, nulls);
	return (0);
}

static	void launch_game(char **map_array, t_map *level)
{
	t_lib	lib;

	printf("launching game..\n");
	printf("first line map_array %s..\n", map_array[0]);
	printf("character file path %s\n", level->character_img);
	printf("w: %d h: %d\n", level->width, level->height);
	printf("tile_pixel: %d\n", level->pixels);

	lib.img = NULL;
	lib.game = mlx_init();
	if (!lib.game)
		exit(1);
	lib.session = mlx_new_window(lib.game, (level->pixels * level->width), (level->pixels * level->height), "Hello world!");
	if (!lib.session)
	 {
		free(lib.game),
		exit(1);
	}
	render_map(lib.img, map_array, level, lib.game, lib.session);
	mlx_key_hook(lib.session, key_hook, &lib); // should be &lib instead of NULL
	mlx_loop(lib.game);
	// free(lib.session);
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
		init_chara_data(map_array, map_data);
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
