/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:47:31 by jjs               #+#    #+#             */
/*   Updated: 2024/09/19 14:00:13 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

// Map checks
void	check_map(char *map_file);
char	*get_next_line(int fd);


#endif