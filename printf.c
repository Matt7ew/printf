/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:43:07 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/03/15 19:57:32 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...)
{
    va_list args;
    int count;

    va_start(args, str);
    count = parse_format(str, args);
    va_end(args);
    return (count);
}
