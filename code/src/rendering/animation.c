/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:57:16 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/08 00:08:15 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int active_char_frames(t_game *level, int frame_counter)
{
	if (frame_counter < 10)
		level->character_img = level->char_frame_0; // 10
	else if (frame_counter < 20)
		level->character_img = level->char_frame_1; // 20
	else if (frame_counter < 30)
		level->character_img = level->char_frame_2; // 30
	else if (frame_counter < 40)
		level->character_img = level->char_frame_1; // 40
	else if (frame_counter < 45)
		level->character_img = level->char_frame_0; // 45
	else
		frame_counter = 0;
	return (frame_counter);
}

int active_exit_frames(t_game *level, int frame_counter)
{
	if (frame_counter < 20) // 80
		level->door_img = "textures/xpm/open_1.xpm";
	else if (frame_counter < 40) // 160
		level->door_img = "textures/xpm/open_2.xpm";
	else if (frame_counter < 60) // 240
		level->door_img = "textures/xpm/open_3.xpm";
	else if (frame_counter < 100) // 320
		level->door_img = "textures/xpm/open_4.xpm";
	else if (frame_counter < 140) // 400
		level->door_img = "textures/xpm/open.xpm";
	else if (frame_counter < 200) // 480
		level->door_img = "textures/xpm/open_4.xpm";
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
