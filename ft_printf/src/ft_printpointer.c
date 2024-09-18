/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@stupwddent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:08:13 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/22 13:52:28 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printhexp(uintptr_t num)
{
	int count = 0;
	char *hex_digits = "0123456789abcdef";

	if (num >= 16)
		count += ft_printhexp(num / 16);
	count += ft_printchar(hex_digits[num % 16]);
	return (count);
}

int	ft_printpointer(uintptr_t ptr)
{
	int count = 0;

	if (ptr == 0)
	{
		count += write(1, "0x0", 3); // check if this case changes on linux
		return count;
	}
	count += ft_printstr("0x");
	count += ft_printhexp(ptr);
	return (count);
}

