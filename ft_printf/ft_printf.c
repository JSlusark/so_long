/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjs <jjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:33:48 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/18 14:35:48 by jjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list args, const char format)
{
	if (format == 'c')
		return (ft_printchar((va_arg(args, int))));
	if (format == 's')
		return (ft_printstr((va_arg(args, char *))));
	if (format == 'i' || format == 'd')
		return (ft_printnum(va_arg(args, int)));
	if (format == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	if (format == 'p')
		return (ft_printpointer(va_arg(args, uintptr_t)));
	if (format == 'x' || format == 'X')
		return (ft_printhex(va_arg(args, int), format));
	if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	count = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *format++))
			count = count + ft_convert(args, *format);
		else
		{
			count = count + ft_printchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
