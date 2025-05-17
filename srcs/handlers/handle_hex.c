/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:14:44 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 07:14:48 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_hex(unsigned int n, int uppercase)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	str = ft_strbase(n, base);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
