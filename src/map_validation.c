/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:10 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/23 17:23:54 by jslusark         ###   ########.fr       */
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

int	has_required_text(char **map) // return 1 if map sym
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
				map[r][c] == 'E' || map[r][c] == 'P')
				c++;
			else
			{
				ft_printf("map does not have required text: %c at r[%d]c[%d]\n", map[r][c], r, c);
				return(0);
			}
		}
		r++;
	}
	return(1);
}

int	count_sprites(char **map, int *f, int *e, int *c, int *p) // return 1 if map sym
{
	int row;
	int col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			ft_printf("%c", map[row][col]);
			if (map[row][col] == 'P')
				(*p)++;
			if (map[row][col] == 'C')
				(*c)++;
			if (map[row][col] == 'E')
				(*e)++;
			if (map[row][col] == '0')
				(*f)++;
			col++;
		}
		ft_printf("\n");
		row++;
	}
	return(1);
}

int	has_enough_sprites(char **map, t_map *map_data) // return 1 if map sym
{
	int f;
	int e;
	int c;
	int p;

	f = 0;
	e = 0;
	c = 0;
	p = 0;
	count_sprites(map, &f, &e, &c, &p);
	if(p == 0 || p > 1)
	{
		ft_printf("amount of P in map is %d\n", p);
		return(0);
	}
	if(c == 0)
	{
		ft_printf("amount of C in map is %d\n", c);
		return(0);
	}
	if(e == 0 || e > 1)
	{
		ft_printf("amount of E in map is %d\n", e);
		return(0);
	}
	// if(f == 0) // check if floor amount needs to be h x w (and go behind everything)
	// {
	// 	ft_printf("amount of F in map is %d\n", f);
	// 	return(0);
	// }
	map_data->c_n = c;
	return(1);
}


int	is_rectangular(char **map, int row, int col) // checks lines for shape, check is not squared
{
	int i;
	int	curr;

	i = 0;
	while (map[i] != NULL)
	{
		curr = ft_strlen(map[i]);
		if (curr != row)
		{
			ft_printf("Map's height is not the same for every row and therefore has no valid shape\n");
			return(0);
		}
		i++;
	}
	if (row == col)
	{
		ft_printf("Map is not rectangular\n");
		return(0);
	}
	return(1);
}

int is_framed(char **map, int last_row, int last_c)
{
	int row;
	int c;

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
						ft_printf("Map is not framed from walls (1)\n");
						return(0);
					}
			}
			else
			{
					if (!ft_strchr("01CEP", map[row][c])) // check this better
					{
						ft_printf("No valid characters inside the map\n");
						return(0);
					}
			}
			c++;
		}
		row++;
	}
	return(1);
}