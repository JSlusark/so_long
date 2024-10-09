/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/09 13:08:36 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static	void launch_game(char **map_array, t_map *level)
{

	void	*game;
	void	*session;
	void	*img;
	// void	*img2;
	int		w = 64;
	int		h = 64;

	printf("launching game..\n");
	printf("first line map_array %s..\n", map_array[0]);
	printf("character file path %s\n", level->character_img);
	printf("w: %d h: %d\n", level->width, level->height);


	game = mlx_init();
	if (!game)
		exit(1);
	session = mlx_new_window(game, (64 * level->width), (64 * level->height), "Hello world!");
	if (!session)
	 {
		free(game),
		exit(1);
	}


	// img = mlx_xpm_file_to_image(game, level->character_img, &w, &h);
	// img2 = mlx_xpm_file_to_image(game, level->floor_img, &w, &h);
	// mlx_put_image_to_window(game, session, img, w, h);
	// mlx_put_image_to_window(game, session, img2, w, h);
		int y = 0; // Loop through rows

		while (map_array[y] != NULL)
	{
		int x = 0; // Loop through columns
		while (map_array[y][x] != '\0')
		{
			if (map_array[y][x] == '1') // Wall
				img = mlx_xpm_file_to_image(game, level->wall_img, &w, &h);
			else if (map_array[y][x] == '0') // Floor
				img = mlx_xpm_file_to_image(game, level->floor_img, &w, &h);
			else if (map_array[y][x] == 'P') // Character
				img = mlx_xpm_file_to_image(game, level->character_img, &w, &h);
			else if (map_array[y][x] == 'E') // Exit
				img = mlx_xpm_file_to_image(game, level->door_img, &w, &h);
			else if (map_array[y][x] == 'C') // Loot
				img = mlx_xpm_file_to_image(game, level->loot_img, &w, &h);

			// Calculate position based on row (y) and column (x)
			if (img != NULL)
				mlx_put_image_to_window(game, session, img, x * w, y * h); // x * w and y * h
			x++; // Move to next column
		}
		y++; // Move to next row
	}


	// // // render map
	// // // at key event count move and update map array and update sprite parsing
	// // // re-render?
	mlx_loop(game);
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
