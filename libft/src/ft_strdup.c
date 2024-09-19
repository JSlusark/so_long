/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:59:20 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/19 15:55:17 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	i;

	duplicate = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (!duplicate)
		return (0);
	if (!duplicate && !s)
		return (duplicate);
	while (i < ft_strlen(s) + 1)
	{
		duplicate[i] = s[i];
		i++;
	}
	return (duplicate);
}
