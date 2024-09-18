/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:12:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:36:35 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
#include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnum(long int num);
int		ft_printunsigned(unsigned int num);
int		ft_printhex(unsigned int num, char format);
int		ft_printpointer(uintptr_t ptr);
//other funcs

#endif
