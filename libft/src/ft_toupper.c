/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:52:36 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:48:55 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_toupper('a')); //A
	printf("%c\n", ft_toupper('b')); //B
	printf("%c\n", ft_toupper('y')); //Y
	printf("%c\n", ft_toupper('x')); //X
	printf("%c\n", ft_toupper('z')); //Z
}*/
