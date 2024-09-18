/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:14 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:48:55 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	printf("y %i\n", ft_isprint('a'));
	printf("n %i\n", ft_isprint('\b'));
	printf("n %i\n", ft_isprint(190));
	printf("y %i\n", ft_isprint('%'));
	printf("y %i\n", ft_isprint('-'));
	printf("y %i\n", ft_isprint('|'));
	printf("n %i\n", ft_isprint('\t'));
} */
