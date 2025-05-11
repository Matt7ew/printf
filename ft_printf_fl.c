/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/06 09:33:15 by matthewjorg      ###   ########.fr       */
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

