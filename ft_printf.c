/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:43:07 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 05:54:16 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (format[i] == '%')
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

int	handle_specifier(char spec, va_list args)
{
	if (spec == 'c')
		return (handle_char(va_arg(args, int)));
	else if (spec == 's')
		return (handle_str(va_arg(args, char *)));
	else if (spec == 'p')
		return (handle_ptr(va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (handle_nbr(va_arg(args, int)));
	else if (spec == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (handle_hex(va_arg(args, unsigned int), (spec == 'X')));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

#include "ft_printf.h"

int	handle_ptr(void *ptr)
{
	char	*str;
	int		len;

	if (!ptr)
		return (write(1, "0x0", 3));
	str = ft_strbase((unsigned long long)ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	len = write(1, "0x", 2);
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_print_prefix(char *prefix)
{
	int	len;

	if (!prefix)
		return (0);
	len = ft_strlen_printf(prefix);
	return (write(1, prefix, len));
}

int	ft_strlen_printf(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}
