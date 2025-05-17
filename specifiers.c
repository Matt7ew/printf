/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:08:51 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 03:04:49 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char s, va_list args, int count)
{
	if (s == '%')
		ft_putchar(s);
	else if (s == 'c')
		ft_putchar(va_arg(args, int));
	else if (s == 's')
		ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		ft_showpointer(va_arg(args, void *));
	else if (s == 'd')
		handle_d_i(va_arg(args, int));
	else if (s == 'i')
		handle_d_i(va_arg(args, int));
	else if (s == 'u')
		handle_u(va_arg(args, int));
	else if (s == 'x')
		ft_print_sx(va_arg(args, unsigned int));
	else if (s == 'X')
		ft_print_bx(va_arg(args, unsigned int));
	else
		return (0);
}
