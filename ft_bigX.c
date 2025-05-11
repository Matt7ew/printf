/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:53:12 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/09 17:58:08 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_BX(unsigned int s)
{
	char	*str;
	int 	rl;


	str = ft_strbase(s, "0123456789ABCDEF");
	if (str == NULL)
		return (-1);
	if (ft_putstr(str) < 0)
	{
		free(str);
		return (-1);
	}
	rl = ft_strlen(str);
	free(str);
	return (rl);
}