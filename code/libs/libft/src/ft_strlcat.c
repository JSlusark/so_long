/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:20 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 12:57:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_i;
	size_t	s_i;

	d_i = 0;
	s_i = 0;
	while (dst[d_i] && d_i < size)
		d_i++;
	while ((src[s_i] != '\0') && ((d_i + s_i + 1) < size))
	{
		dst[d_i + s_i] = src[s_i];
		s_i++;
	}
	if (d_i != size)
		dst[d_i + s_i] = '\0';
	return (d_i + ft_strlen(src));
}
