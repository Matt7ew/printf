/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:52 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 04:20:04 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_showpointer(void *p)
{
	unsigned long long	ptr;
	char				*s;
	int					rl;
	int					tmp;

	if (!p)
		return (write(1, "(nil)", 5));
	ptr = (unsigned long long)p;
	if (!(s = ft_strbase(ptr, "0123456789abcdef")))
		return (-1);
	rl = write(1, "0x", 2);
	if (rl == -1)
		return (free(s), -1);
	tmp = write(1, s, ft_strlen(s));
	free(s);
	if (tmp == -1)
		return (-1);
	return (rl + tmp);
}

int	ft_str_unique(char *base)
{
	int	i;
	int	j;

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
		return (0);
	ft_putstr_fd(str, 1);
	rl = strlen(str);
	free(str);
	return (rl);
}

int	ft_print_sx(unsigned int s)
{
	char	*str;
	int		rl;

	str = ft_strbase(s, "0123456789abcdef");
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	rl = strlen(str);
	free(str);
	return (rl);
}
