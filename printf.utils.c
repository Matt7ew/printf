/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:52 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/04/25 10:52:24 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_showpointer(void *p)
{
	unsigned long long int	ptr;
	char					*s;
	int						rl;

	ptr = (unsigned long long int)p;
	if (p == NULL)
		return (null_pointer());
	s = ft_strbase(ptr, "0123456789abcdef");
	if (s == NULL)
		return (-1);
	if (ft_putstr("0x") < 0)
	{
		free(s);
		return (-1);
	}
	if (ft_putstr(s) < 0)
	{
		free(s);
		return (-1);
	}
	rl = ft_strlen(s) + 2;
	free(s);
	return (rl);
} 

int ft_str_unique(unsigned char *base)
{
	size_t length;
	size_t str1;
	size_t check;

	length = ft_strlen(base);
	str1 = 0;

	while(str1  < length)
	{
		check = str1 + 1;
		while(check < length)
		{
			if(base[str1] == base[check])
				return(0);
			check++;
		}
		str1++;
	}
	return(1);
}
