/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:14:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*get_file(char c, t_map *level)
{
	if (c == '1')
		return (level->wall_img);
	else if (c == '0')
		return (level->floor_img);
	else if (c == 'P')
		return (level->character_img);
	else if (c == 'E')
		return (level->door_img);
	else if (c == 'C')
		return (level->loot_img);
	else if (c == 'K')
		return (level->enemy_img);
	return (NULL);
}

void	render_map(void *img, char **map_array, t_map *level, t_lib lib)
{
	int		y;
	int		x;
	char	*file;

	y = 0;
	while (map_array[y] != NULL)
	{
		x = 0;
		while (map_array[y][x] != '\0')
		{
			file = get_file(map_array[y][x], level);
			img = mlx_xpm_file_to_image(lib.game, file,
					&level->pixels, &level->pixels);
			if (img != NULL)
			{
				mlx_put_image_to_window(lib.game, lib.session,
					img, x * level->pixels, y * level->pixels);
				mlx_destroy_image(lib.game, img);
			}
			x++;
		}
		y++;
	}
}
