/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:34:27 by jslusark          #+#    #+#             */
/*   Updated: 2025/08/13 11:55:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void print_chara_data(t_sprite *c)
{
	ft_printf("CHARACTER POSITION AND SURROUNDING ELEMENTS:\n");
	ft_printf(" %c     ⬆️\n", *(c->up_i->ptr));
	ft_printf("%c%c%c   ⬅️ ➡️\n",
			  *(c->left_i->ptr), *(c->ptr), *(c->right_i->ptr));
	ft_printf(" %c     ⬇️\n", *(c->down_i->ptr));
}

void print_map(char **map_array)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (map_array[i] != NULL)
	{
		ft_printf("%s\n", map_array[i]);
		i++;
	}
	ft_printf("\n");
}

void print_controls(t_game *level, char *direction)
{
	ft_printf("Moving %s\n", direction);
	ft_printf("UP position map_arr[%d][%d], symbol %c\n",
			  level->character_data->up_i->x, level->character_data->up_i->y,
			  *(level->character_data->up_i->ptr));
	ft_printf("CH position map_arr[%d][%d], symbol %c\n",
			  level->character_data->curr_i->x, level->character_data->curr_i->y,
			  *(level->character_data->curr_i->ptr));
}
