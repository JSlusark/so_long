/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:10 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:48:55 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*#include <stdio.h>
int	main(void)
{
	printf("y %i\n", ft_isascii('a'));
	printf("n %i\n", ft_isascii(128));
	printf("n %i\n", ft_isascii(190));
	printf("y %i\n", ft_isascii('\t'));
	printf("y %i\n", ft_isascii('9'));
	printf("y %i\n", ft_isascii('\n'));
	printf("n %i\n", ft_isascii(-10));
}*/
