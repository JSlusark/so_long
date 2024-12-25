/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:57:16 by jslusark          #+#    #+#             */
/*   Updated: 2024/12/25 21:08:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	active_char_frames(t_map *level, int frame_counter)
{
	if (frame_counter < 1)
		level->character_img = level->char_frame_0; // 1
	else if (frame_counter < 3)
		level->character_img = level->char_frame_1; // 3
	else if (frame_counter < 4)
		level->character_img = level->char_frame_2; // 4
	else if (frame_counter < 5)
		level->character_img = level->char_frame_1; // 5
	else if (frame_counter < 7)
		level->character_img = level->char_frame_0; // 7
	else
		frame_counter = 0;
	return (frame_counter);
}

int	active_exit_frames(t_map *level, int frame_counter)
{
	if (frame_counter < 2) // 80
		level->door_img = "textures/xpm/open_1.xpm";
	else if (frame_counter < 4) // 160
		level->door_img = "textures/xpm/open_2.xpm";
	else if (frame_counter < 6) // 240
		level->door_img = "textures/xpm/open_3.xpm";
	else if (frame_counter < 8) // 320
		level->door_img = "textures/xpm/open_4.xpm";
	else if (frame_counter < 10) // 400
		level->door_img = "textures/xpm/open.xpm";
	else if (frame_counter < 12) // 480
		level->door_img = "textures/xpm/open_4.xpm";
	else
		frame_counter = 4; // 160
	return (frame_counter);
}

int	animation(t_map *level)
{
	static int	exit_animation = 0;
	static int	char_animation = 0;
	char_animation = active_char_frames(level, char_animation);
	char_animation++;
	if (level->activation == 1)
	{
		exit_animation = active_exit_frames(level, exit_animation);
		exit_animation++;
	}
	rerender_game(level); // was part of line 67
	return (0);
}
