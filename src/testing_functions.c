/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:34:27 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/16 11:52:43 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_chara_data(t_sprite *c)
{
	// printf("symbol: %c\n", c->ptr);
	// printf("moves: %d\n", c->moves);
	// printf("loot collected: %d\n", c->loot_collected);
	// printf("position map_array[%d][%d]\n", c->curr_i->x, c->curr_i->y);

	printf("CHARACTER POSITION AND SURROUNDING ELEMENTS:\n");
	printf(" %c     ⬆️\n",*(c->up_i->ptr));
	printf("%c%c%c   ⬅️ ➡️\n",*(c->left_i->ptr), *(c->ptr), *(c->right_i->ptr));
	printf(" %c     ⬇️\n",*(c->down_i->ptr));

	// printf("symbol: %c\n", c->up_i->ptr);
	// printf("position map_array[%d][%d]\n", c->up_i->x, c->up_i->y);

}

void print_map(char **map_array)
{
    int i = 0;

    while (map_array[i] != NULL)
    {
        printf("%s\n", map_array[i]);
        i++;
    }
}
