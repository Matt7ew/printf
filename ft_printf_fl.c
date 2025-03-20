/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/03/13 11:32:19 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int parse_format(const char *format, va_list args)
{
    int count = 0;
    int i = 0;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++; // Move past '%'
            if (!format[i]) // Edge case: ends with %
                break;
            count = handle_specifier(format[i], args, count);
            if (count == -1)
                return (-1); // Propagate write error
        }
        else
        {
            if (write(1, &format[i], 1) == -1)
                return (-1);
            count++;
        }
        i++;
    }
    return (count);
}
int handle_specifier(char s, va_list args, int count)
{
    
}