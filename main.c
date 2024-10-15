/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/15 17:41:29 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map	*level)
{

	// if direction is wall do nothing  x
	// if direction is passable increase moves
	// if direction is loot decrease loot_n
	// if direction is door
	//		if loot_n is not 0 return
	// 		else change position, re-render and close YOU WIN
	// if direction is anything instead than wall, increase moves

	// printf("\n\n keycode: %d, %d\n", keycode, level->width); // 65293 is x11 keycode
	if (keycode == UP_KEY || keycode == W_KEY)
	{
		// printf("Moving up!\n");
		// printf("UP position map_arr[%d][%d], symbol %c\n", level->character_data->up_i->x, level->character_data->up_i->y, *(level->character_data->up_i->ptr));
		// printf("CH position map_arr[%d][%d], symbol %c\n", level->character_data->curr_i->x, level->character_data->curr_i->y, *(level->character_data->curr_i->ptr));

		change_map(level->character_data->up_i->ptr, level->character_data->curr_i->ptr, level);

	}
	else if (keycode == DOWN_KEY || keycode == S_KEY)
	{
		// printf("Moving down!\n");
		// printf("DOWN position map_arr[%d][%d], symbol %c\n", level->character_data->down_i->x, level->character_data->down_i->y, *(level->character_data->down_i->ptr));
		// printf("CHAR position map_arr[%d][%d], symbol %c\n", level->character_data->curr_i->x, level->character_data->curr_i->y, *(level->character_data->curr_i->ptr));
		change_map(level->character_data->down_i->ptr, level->character_data->curr_i->ptr, level);
	}
	else if (keycode == LEFT_KEY || keycode == A_KEY)
	{
		// Move character left
		// printf("Moving left!\n");
		// printf("LEFT position map_arr[%d][%d], symbol %c\n", level->character_data->left_i->x, level->character_data->left_i->y, *(level->character_data->left_i->ptr));
		// printf("CHAR position map_arr[%d][%d], symbol %c\n", level->character_data->curr_i->x, level->character_data->curr_i->y, *(level->character_data->curr_i->ptr));
		change_map(level->character_data->left_i->ptr, level->character_data->curr_i->ptr, level);
	}
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
	{
		// Move character right
		// printf("Moving right!\n");
		// printf("RIGHT position map_arr[%d][%d], symbol %c\n", level->character_data->right_i->x, level->character_data->right_i->y, *(level->character_data->right_i->ptr));
		// printf("CHARA position map_arr[%d][%d], symbol %c\n", level->character_data->curr_i->x, level->character_data->curr_i->y, *(level->character_data->curr_i->ptr));
		change_map(level->character_data->right_i->ptr, level->character_data->curr_i->ptr, level);
	}
	else if (keycode == 65307 || keycode == Q_KEY) // <------this does not work
	{
		exit(0);
		// close_window(lib);
		// mlx_destroy_window(lib.game, lib.session);
		printf("Clicked exit!\n");
	}
	else // to handle open keypress
		return(0);
	// printf("move %d", level->character_data->moves);
	// printf("keycode: %d, %d\n", keycode, nulls);
	// return (0);
	init_chara_data(level->map_array, level);
	render_map(level->mini_libx.img, level->map_array, level, level->mini_libx.game, level->mini_libx.session);// <-
	return (0);
}

static	void launch_game(char **map_array, t_map *level)
{
	// level->mini_libx = malloc(sizeof(t_lib));
	// t_lib	lib;
	// lib
	// print_chara_data(level->character_data); // this stays TRY IN PALGAME

	// printf("launching game..\n");
	// printf("first line map_array %s..\n", map_array[0]);
	// printf("character file path %s\n", level->character_img);
	// printf("w: %d h: %d\n", level->width, level->height);
	// printf("tile_pixel: %d\n", level->pixels);

	// level->mini_libx.img = NULL;
	level->mini_libx.game = mlx_init();
	if (!level->mini_libx.game)
		exit(1);
	level->mini_libx.session = mlx_new_window(level->mini_libx.game, (level->pixels * level->width), (level->pixels * level->height), "Hello world!");
	if (!level->mini_libx.session)
	 {
		free(level->mini_libx.game),
		exit(1);
	}
	render_map(level->mini_libx.img, map_array, level, level->mini_libx.game, level->mini_libx.session);// <-
	mlx_key_hook(level->mini_libx.session, key_hook, level); // should be &mini_libx instead of NULL
	mlx_loop(level->mini_libx.game);
	// free(lib.session);
	// free(game);
}

int	main(int argc, char **argv)
{
	// char	**map_array;
	t_map	*map_data;
	printf("NOTE: PLEASE REMEMBER TO REPLACE WITH YOUR CORRECTED PRINTF\n");
	if (argc == 2)
	{
		map_data = malloc(sizeof(t_map));
		map_data->map_array = get_map(argv[1], map_data);
		collect_sprites(map_data->map_array, map_data);
		init_chara_data(map_data->map_array, map_data);
		// init_chara_data(map_array, &map_data); // <---- check if it goes here or better elsewhere and if needed
		printf("Location: main.c h:%d w:%d\n", map_data->height, map_data->width);
		// add function to see if map is bigger than screen res ❗❗❗
		launch_game(map_data->map_array, map_data);
		free(map_data); // IMPORTANT!!
		free_map(map_data->map_array); // IMPORTANT!!
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
