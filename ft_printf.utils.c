/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:52 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 06:15:17 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	handle_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	handle_char(int c)
{
	return (write(1, &c, 1));
}

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

int	handle_nbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
