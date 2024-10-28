/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:57:16 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/28 09:19:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	active_exit_frames(t_map *level, int frame_counter)
{
	if (frame_counter < 80)
		level->door_img = "textures/xpm/open_1.xpm";
	else if (frame_counter < 160)
		level->door_img = "textures/xpm/open_2.xpm";
	else if (frame_counter < 240)
		level->door_img = "textures/xpm/open_3.xpm";
	else if (frame_counter < 320)
		level->door_img = "textures/xpm/open_4.xpm";
	else if (frame_counter < 400)
		level->door_img = "textures/xpm/open.xpm";
	else if (frame_counter < 480)
		level->door_img = "textures/xpm/open_4.xpm";
	else
		frame_counter = 160;
	return (frame_counter);
}

int	animation(t_map *level)
{
	static int	frame_counter = 0;

	if (level->activation == 1)
	{
		frame_counter = active_exit_frames(level, frame_counter);
		frame_counter++;
		rerender_game(level);
	}
	return (0);
}
