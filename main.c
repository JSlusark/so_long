/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:39 by jjs               #+#    #+#             */
/*   Updated: 2024/09/18 14:02:43 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
//     if (!mlx)
//         return(1);
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "SO LONG");
// 	if (!mlx_win)
//     {
//         return(free(mlx), 1);
//     }
//     img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// mlx_loop(mlx);
//     mlx_destroy_window(mlx, mlx_win);
// 	mlx_destroy_display(mlx);
//     free(mlx);
//     free(img.img);
//     free(img.addr);
// }

// int	launch_game(char *map_file)
// {
// 	//run an error message if the map file is not .ber extention and if invalid
// }


int main(int argc, char **argv)
{
	// if(argc == 2)
	// 	launch_game(argv[1]);
	if(argc == 2)
		ft_printf("launching game %c ..", argv[1][0]);
	// else
		ft_printf("./so_long requires a file from the map folder to run!");
	// return (0);
}