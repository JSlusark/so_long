/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/09/19 14:05:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void launch_game(char *map_file)
{
	ft_printf("launching game %c ..\n", map_file[0]);
	check_map(map_file); // maybe let it return a true statement after all map checks done
	// do most checks before laucnhing mlx to avoid repeating unnecessary frees
	// CHECKS IN MIND(for now):
	// MAP checks
	//		is_rectangular
	//		is_same_len (prob included in check above)
	//		includes_correct_symbols (P, C, 1, E, 0)
	//		is_framed (checks if line 1 and last have all 1/walls, and mid lines 1st and last has one 1 while middle 0/empty )
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