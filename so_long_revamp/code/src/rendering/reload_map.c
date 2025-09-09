/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/09 16:25:21 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void rerender_game(t_game *level)
{
	// could put the reload map fucntion here
	get_chara_position(level->map_array, level->character_data);
	render_map(level->mini_libx.img, level->map_array, level,
			   level->mini_libx);
}