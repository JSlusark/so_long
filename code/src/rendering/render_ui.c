/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/09/07 22:31:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void show_status_bar(t_game *level)
{
	char *moves_text;
	int i;
	int w = 5;
	int h = 5;

	i = 0;
	level->heart_icon = mlx_xpm_file_to_image(level->mini_libx.game,
											  "textures/xpm/heart_icon.xpm", &w, &h);
	moves_text = ft_itoa(level->moves);
	if (!moves_text)
		return; // Handle memory allocation failure

	// Display moves on the screen at coordinates (10, 10)
	// ft_printf("hello");
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   60, 20, 0xFFFFFF, moves_text);
	mlx_string_put(level->mini_libx.game, level->mini_libx.session,
				   100, 20, 0xFFFFFF, "Lives: ");
	while (i < level->lives)
	{
		mlx_put_image_to_window(level->mini_libx.game, level->mini_libx.session,
								level->heart_icon, 145 + i * (h), 8);
		i++;
	}
	//  mlx_destroy_image(g->mini_libx.game, heart); // free after use
	free(moves_text);
}