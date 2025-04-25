/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:08:51 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/04/24 11:56:32 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_specifier(char s, va_list args, int count)
{
    if (s == '%')
        ft_putchar(s);
    else if (s == 'c')
        ft_putchar(va_arg(args, int));
    else if (s == 's')
        ft_putstr(va_arg(args, char*));
    else if (s == 'p')
        ft_showpointer(va_arg(args, void*));
    else if (s == 'd')
    else if (s == 'i')
    else if (s == 'u')
    else if (s == 'x')
    else if (s == 'X')
}