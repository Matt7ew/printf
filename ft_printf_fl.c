/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/04/24 11:55:21 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int parse_format(const char *str, va_list args)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '%')
        {
            i++; // Move past '%'
            if (!str[i]) // Edge case: ends with %
                break;
            count = handle_specifier(str[i], args, count);
            if (count == -1)
                return (-1); // Propagate write error
        }
        else
        {
            if (write(1, &str[i], 1) == -1)
                return (-1);
            count++;
        }
        i++;
    }
    return (count);
}
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
