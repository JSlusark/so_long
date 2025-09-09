/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:57:16 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/09 16:03:13 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int active_char_frames(t_game *level, int frame_counter)
{
	if (frame_counter < 80)
		level->character_img = level->char_frame_0; // 10
	else if (frame_counter < 160)
		level->character_img = level->char_frame_1; // 20
	else if (frame_counter < 240)
		level->character_img = level->char_frame_2; // 30
	else if (frame_counter < 320)
		level->character_img = level->char_frame_1; // 40
	else if (frame_counter < 400)
		level->character_img = level->char_frame_0; // 45
	else
		frame_counter = 0;
	return (frame_counter);
}

int active_exit_frames(t_game *level, int frame_counter)
{
	if (frame_counter < 80) // 80 a:20
		level->door_img = "assets/xpm/open_1.xpm";
	else if (frame_counter < 160) // 160 a:40
		level->door_img = "assets/xpm/open_2.xpm";
	else if (frame_counter < 240) // 240 a:60
		level->door_img = "assets/xpm/open_3.xpm";
	else if (frame_counter < 320) // 320 a:100
		level->door_img = "assets/xpm/open_4.xpm";
	else if (frame_counter < 400) // 400 a:140
		level->door_img = "assets/xpm/open.xpm";
	else if (frame_counter < 480) // 480 a:200
		level->door_img = "assets/xpm/open_4.xpm";
	else
		frame_counter = 100; // 240
	return (frame_counter);
}

int animation(t_game *level)
{
	static int exit_animation = 0;
	static int char_animation = 0;
	char_animation = active_char_frames(level, char_animation);
	char_animation++;
	if (level->exit_active == 1)
	{
		exit_animation = active_exit_frames(level, exit_animation);
		exit_animation++;
	}
	rerender_game(level); // was part of line 67
	return (0);
}
