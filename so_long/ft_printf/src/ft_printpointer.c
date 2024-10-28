/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:08:13 by jslusark          #+#    #+#             */
/*   Updated: 2024/10/25 13:05:02 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printhexp(uintptr_t num)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (num >= 16)
		count += ft_printhexp(num / 16);
	count += ft_printchar(hex_digits[num % 16]);
	return (count);
}

int	ft_printpointer(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "0x0", 3);
		return (count);
	}
	count += ft_printstr("0x");
	count += ft_printhexp(ptr);
	return (count);
}
