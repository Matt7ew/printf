/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:06:45 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 07:07:29 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
	}
	return (1);
}

char	*ft_strbase(unsigned long long n, char *base)
{
	char *str;
	int base_len;
	int digits;

	if (!check_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	digits = (n == 0) ? 1 : 0;
	while (n > 0 && ++digits)
		n /= base_len;
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits--] = '\0';
	n = (n == 0) ? 0 : n;
	while (digits >= 0)
	{
		str[digits--] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}