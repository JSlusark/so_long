/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:30:49 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:34 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printhex(unsigned int num, char format)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_printhex(num / 16, format);
	count += ft_printchar(hex_digits[num % 16]);
	return (count);
}
