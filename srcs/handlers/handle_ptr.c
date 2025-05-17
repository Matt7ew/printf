/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:10:15 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 07:12:11 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
