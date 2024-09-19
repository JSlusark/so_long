/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:10 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/19 19:53:31 by jslusark         ###   ########.fr       */
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

int	find_map_height(char **map)
{
	int line;
	line = 0;
	while (map[line] != '\0')
		line++;
	return(line);
}

int	is_rectangular(char **map)
{
	int width;
	int	height;

	width = ft_strlen(map[0]);
	height = find_map_height(map);
	if (width < 3 && width < height)
		return (0);
	return(1);
}
int	has_same_width(char **map) // check if all lines have the same len of char
{
	int line;
	int line_len;
	int	nextline_len;
	int c;

	line_len = ft_strlen(map[0]);
	line = 1;
	while (map[line] != '\0')
	{
		nextline_len = ft_strlen(map[line]);
		if (line_len != nextline_len)
			return (0);
		line++;
	}
	return(1);
}

int	contains_symbols(char **map) // return 1 if map sym
{
	int line;
	int c;

	line = 0;
	while (map[line] != '\0')
	{
		c = 0;
		while (map[line][c] != '\0')
		{
			if (!ft_strchr("01CEP", map[line][c]))
				return(0);
			c++;
		}
		line++;
	}
	return(1);
}

int is_framed(char **map)
{
	int line;
	int c;

	line = 0;
	while (map[line] != '\0')
	{
		c = 0;
		while (map[line][c] != '\0')
		{
			// if line is 1st and line is last
				// if avy character does not contain "1" return 0 if not continue loop
			if (line == 0 || line == last_line)
			{
				if (!ft_strchr("1", map[line][c]))
					return(0);
			}
			// else (remainng lines)
				// if c 1st and clast do not contain "1" return 0 if not continue loop
			else
			{
				if (c == 0 || c == last_char)
				{
					if (!ft_strchr("1", map[line][c]))
					return(0);
				}
			}
			c++;
		}
		line++;
	}
	return(1);

}