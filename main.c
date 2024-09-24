/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/09/24 15:59:17 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void launch_game(char **map_array)
{
	printf("launching game..\n");
	 int i = 0;
	while (map_array[i] != NULL)
	{
		printf("%s\n", map_array[i]);
		i++;
	}

	// check_map(map_file); // maybe let it return a true statement after all map checks done
	// do most checks before laucnhing mlx to avoid repeating unnecessary frees
	// MAP FORMAT & PARSING
	// ASSETS
	//	 ASSET LAYOUT CHECK
	//		- problems with items spreading om the page and interacting
	//	 ASSET GRAPHIC CONV CHECK ?

}

int main(int argc, char **argv)
{
	char	**map_array;
	t_map	map_data;
	printf("NOTE: PLEASE REMEMBER TO REPLACE WITH YOUR CORRECTED PRINTF\n");

	// map_data = NULL;
	if(argc == 2)
	{
		map_array = get_map(argv[1], &map_data); // maybe let it return a true statement after all map checks done
		launch_game(map_array);
		free_map(map_array); // IMPORTANT!!
	}
	else
	{
		printf("./so_long requires a file from the map folder to run!\n");
		exit(1);
	}
	return (0);
}