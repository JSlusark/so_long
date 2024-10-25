/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:50 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:48:55 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*alt;
	size_t		i;

	i = ft_strlen(s);
	alt = (char *)s;
	if (c == '\0')
		return (&alt[i]);
	while (i != 0)
	{
		if (alt[i] == (char)c)
		{
			return (&alt[i]);
		}
		i--;
	}
	if (s[i] == (char)c)
		return (alt);
	return (0);
}
