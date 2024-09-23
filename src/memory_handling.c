/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:42:30 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/23 16:03:17 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map_layout)
{
	int i;

	i = 0;
	while (map_layout[i])
	{
		free(map_layout[i]);
		i++;
	}
	free(map_layout);
}