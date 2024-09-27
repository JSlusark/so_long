/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/09/27 18:13:56 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void launch_game(char **map_array, t_map *map_data)
{

	// void	*game;
	// void	*mlx_win;
	// void	wall;
	// void	floor;
	// void	exit;
	// void	chara;
	// void	loot;

	printf("launching game..\n");
	printf("first line map_array %s..\n", map_array[0]);
	printf("character file path %d\n", map_data->width);
	// printf("character file path %d\n", map_data->character_img);
	// game = mlx_init();
	// mlx_win = mlx_new_window(mlx, (map->width * 32), (map->height * 32), "SO_LONG");
	// if (!mlx_win)
	//  {
	// 	free(mlx),
	// 	exit(1);
	// }
	// if (!mlx)
	// 	exit(1);
	// // render map
	// // at key event count move and update map array and update sprite parsing
	// // re-render?
	// mlx_loop(game);
	// free(mlx);


}

int main(int argc, char **argv)
{
	char	**map_array;
	t_map	map_data;
	printf("NOTE: PLEASE REMEMBER TO REPLACE WITH YOUR CORRECTED PRINTF\n");

	if (argc == 2)
	{
		map_array = get_map(argv[1], &map_data);
		collect_sprites(map_array, &map_data);
		// init_chara_data(map_array, &map_data);
		launch_game(map_array, &map_data);
		free_map(map_array); // IMPORTANT!!
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
