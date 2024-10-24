/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:34:27 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/24 18:55:44 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_chara_data(t_sprite *c)
{
	printf("CHARACTER POSITION AND SURROUNDING ELEMENTS:\n");
	printf(" %c     ⬆️\n",*(c->up_i->ptr));
	printf("%c%c%c   ⬅️ ➡️\n",*(c->left_i->ptr), *(c->ptr), *(c->right_i->ptr));
	printf(" %c     ⬇️\n",*(c->down_i->ptr));
}

void	print_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i] != NULL)
	{
		printf("%s\n", map_array[i]);
		i++;
	}
}

void	print_controls(t_map *level, char *direction)
{
	printf("Moving %s\n", direction);
	printf("UP position map_arr[%d][%d], symbol %c\n",
		level->character_data->up_i->x, level->character_data->up_i->y,
		*(level->character_data->up_i->ptr));
	printf("CH position map_arr[%d][%d], symbol %c\n",
		level->character_data->curr_i->x, level->character_data->curr_i->y,
		*(level->character_data->curr_i->ptr));
}
