/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/03/23 16:35:01 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

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
    if (s == 'c')
        ft_putchar(va_arg(args, char));
    if ("")
    if ("")
    if ("")
    if ("")
    if ("")
    if ("")
    if ("")
}
