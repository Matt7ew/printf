/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:52 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 02:17:09 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_showpointer(void *p)
{
	unsigned long long	ptr;
	char				*s;
	int					rl;

	if (p == NULL)
		return (ft_putstr("0x0"));
	ptr = (unsigned long long)p;
	s = ft_strbase(ptr, "0123456789abcdef");
	if (!s)
		return (-1);
	rl = ft_putstr("0x");
	if (rl == -1)
	{
		free(s);
		return (-1);
	}
	rl += ft_putstr(s);
	free(s);
	return (rl);
}

int	ft_str_unique(char *base)
{
	size_t	i;
	size_t	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	ft_print_bx(unsigned int s)
{
	char	*str;
	int		rl;

	str = ft_strbase(s, "0123456789ABCDEF");
	if (!str)
		return (-1);
	rl = ft_putstr(str);
	free(str);
	return (rl);
}

int	ft_print_sx(unsigned int s)
{
	char	*str;
	int		rl;

	str = ft_strbase(s, "0123456789abcdef");
	if (!str)
		return (-1);
	rl = ft_putstr(str);
	free(str);
	return (rl);
}
