/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:20:44 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 08:27:06 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_specifier(char c, va_list args)
{
	if (c == 'c')
		return (handle_char(va_arg(args, int)));
	else if (c == 's')
		return (handle_str(va_arg(args, char *)));
	else if (c == 'p')
		return (handle_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (handle_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (handle_hex(va_arg(args, unsigned int), (c == 'X')));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_specifier(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
