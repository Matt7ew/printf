/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 02:11:01 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_format(const char *str, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			count += handle_specifier(str[i], args);
			if (count == -1)
				return (-1);
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
