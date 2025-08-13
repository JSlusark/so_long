/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:10 by jslusark          #+#    #+#             */
/*   Updated: 2025/08/13 11:55:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int has_required_text(char **map)
{
	int r;
	int c;

	r = 0;
	while (map[r] != NULL)
	{
		c = 0;
		while (map[r][c] != '\0')
		{
			if (map[r][c] == '0' || map[r][c] == '1' || map[r][c] == 'C' ||
				map[r][c] == 'E' || map[r][c] == 'P' || map[r][c] == 'K')
				c++;
			else
			{
				ft_printf("Error: text %c at r[%d]c[%d]\n", map[r][c], r, c);
				return (0);
			}
		}
		r++;
	}
	return (1);
}

static int count_sprite(char **map, char c)
{
	int row;
	int col;
	int amount;

	amount = 0;
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == c)
				amount++;
			col++;
		}
		row++;
	}
	return (amount);
}

int has_enough_sprites(char **map, t_game *map_data)
{
	int e;
	int c;
	int p;
	int k;

	e = count_sprite(map, 'E');
	c = count_sprite(map, 'C');
	p = count_sprite(map, 'P');
	k = count_sprite(map, 'K');
	if (p == 0 || p > 1 || c == 0 || e == 0 || e > 1 || k == 0)
	{
		ft_printf("Error: Map does not have the required amount assets:\n");
		ft_printf("- C: %d (needs to be 1 or more) \n", c);
		ft_printf("- P: %d (needs to be 1) \n", p);
		ft_printf("- E: %d (needs to be 1) \n", e);
		ft_printf("- K: %d (needs to be 1 or more) \n", e);
		return (0);
	}
	map_data->loot_n = c;
	map_data->moves = 0;
	return (1);
}

int is_rectangular(char **map, int row, int col)
{
	int i;
	int curr;

	i = 0;
	while (map[i] != NULL)
	{
		curr = ft_strlen(map[i]);
		if (curr != row)
		{
			ft_printf("Error: height of each row is not the same\n");
			return (0);
		}
		i++;
	}
	if (row == col)
	{
		ft_printf("Error: Map is has to be rectangular not squared\n");
		return (0);
	}
	return (1);
}

int is_framed(char **map, int last_r, int last_c)
{
	int r;
	int c;

	r = 0;
	while (map[r] != NULL)
	{
		c = 0;
		while (map[r][c] != '\0')
		{
			if (r == 0 || r == last_r || c == 0 || c == last_c)
			{
				if (map[r][c] != '1')
				{
					ft_printf("Error: Not framed at map[%d][%d]\n", r, c);
					return (0);
				}
			}
			c++;
		}
		r++;
	}
	return (1);
}
