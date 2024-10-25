/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:32 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 12:58:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			s_len;
	char		*b;
	char		*l;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	b = (char *)big;
	l = (char *)little;
	s_len = ft_strlen(l);
	while (b[i] != '\0' && (i + s_len) <= len)
	{
		if (ft_strncmp((b + i), l, s_len) == 0)
		{
			return (b + i);
		}
		i++;
	}
	return (NULL);
}
