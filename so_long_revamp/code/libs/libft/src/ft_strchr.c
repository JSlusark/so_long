/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:18 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 13:00:26 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
