/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/10/21 19:25:59 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map	*level)
{
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
		free_all_gamedata(level);
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
	free_sprite(level->character_data);
	init_chara_data(level->map_array, level);
	render_map(level->mini_libx.img, level->map_array, level, level->mini_libx.game, level->mini_libx.session);// <-
	return (0);
}

int close_window(t_map *level)
{
    // Free all game data before exiting
    free_all_gamedata(level);
    exit(0);
}

static	void launch_game(char **map_array, t_map *level)
{
	// // print_chara_data(level->character_data); // this stays TRY IN PALGAME
	level->mini_libx.game = mlx_init();
	if (!level->mini_libx.game)
		exit(1);
	level->mini_libx.session = mlx_new_window(level->mini_libx.game, (level->pixels * level->width), (level->pixels * level->height), "SO_LONG");
	if (!level->mini_libx.session)
	 {
		free(level->mini_libx.game),
		exit(1);
	}
	render_map(level->mini_libx.img, map_array, level, level->mini_libx.game, level->mini_libx.session);// <-
	mlx_hook(level->mini_libx.session, 17, 0L, close_window, level);  // Event 17 handles window close (X button)
	mlx_key_hook(level->mini_libx.session, key_hook, level);
	mlx_loop(level->mini_libx.game);
	print_map(map_array);
	print_map(level->map_array);
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
		verify_playability(level); // floowdfill check E C P
		// // add function to see if map is bigger than screen res ❗❗❗
		launch_game(level->map_array, level);
		free_all_gamedata(level); // IMORTANT!! it should free everything besides ministuff
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}
