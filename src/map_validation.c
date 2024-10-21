/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:10 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/21 15:20:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//contains_symbols()
//			checks if map cointains any of the letters needed 01CEP
//has_width()
//			checks that every line has the same len
//is_framed()
//			checks that the walls (1) contain the whole game
//is_rextangular() -> supported by find map height
//			checks that map is rectangular

#include "../so_long.h"

int	has_required_text(char **map)
{
	int	r;
	int	c;

	r = 0;
	while (map[r] != NULL)
	{
		c = 0;
		while (map[r][c] != '\0')
		{
			if (map[r][c] == '0' || map[r][c] == '1' || map[r][c] == 'C' ||
				map[r][c] == 'E' || map[r][c] == 'P')
				c++;
			else
			{
				printf("Error: text %c at r[%d]c[%d]\n", map[r][c], r, c);
				return (0);
			}
		}
		r++;
	}
	return (1);
}

static int	count_sprite(char **map, char c)
{
	int	row;
	int	col;
	int	amount;

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

int	has_enough_sprites(char **map, t_map *map_data)
{
	int	f;
	int	e;
	int	c;
	int	p;

	f = count_sprite(map, '0');
	e = count_sprite(map, 'E');
	c = count_sprite(map, 'C');
	p = count_sprite(map, 'P');
	if (p == 0 || p > 1 || c == 0 || e == 0 || e > 1)
	{
		printf("Map does not have the required amount assets:\n");
		printf("- C: %d (needs to be 1 or more) \n", c);
		printf("- P: %d (needs to be 1) \n", p);
		printf("- E: %d (needs to be 1) \n", e);
		return (0);
	}
	map_data->loot_n = c;
	map_data->moves = 0;
	return (1);
}


int	is_rectangular(char **map, int row, int col)
{
	int	i;
	int	curr;

	i = 0;
	while (map[i] != NULL)
	{
		curr = ft_strlen(map[i]);
		if (curr != row)
		{
			printf("Error: height of each row is not the same\n");
			return (0);
		}
		i++;
	}
	if (row == col)
	{
		printf("Map is not rectangular\n");
		return (0);
	}
	return (1);
}

int	is_framed(char **map, int last_row, int last_c)
{
	int	row;
	int	c;

	row = 0;
	while (map[row] != NULL)
	{
		c = 0;
		while (map[row][c] != '\0')
		{
			if (row == 0 || row == last_row || c == 0 || c == last_c)
			{
				if (map[row][c] != '1')
				{
					printf("Map is not framed from walls (1)\n");
					return (0);
				}
			}
			c++;
		}
		row++;
	}
	return (1);
}
