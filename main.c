/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/09/19 19:57:12 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void launch_game(char *map_file)
{
	ft_printf("launching game %c ..\n", map_file[0]);
	check_map(map_file); // maybe let it return a true statement after all map checks done
	// do most checks before laucnhing mlx to avoid repeating unnecessary frees
	// MAP FORMAT & PARSING
	// ASSETS
	//	 ASSET LAYOUT CHECK
	//		- problems with items spreading om the page and interacting
	//	 ASSET GRAPHIC CONV CHECK ?

}

int main(int argc, char **argv)
{
	if(argc == 2)
		launch_game(argv[1]);
	else
		ft_printf("./so_long requires a file from the map folder to run!\n");
	return (0);
}