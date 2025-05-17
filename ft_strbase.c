/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:30:07 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 05:47:46 by mjorge           ###   ########.fr       */
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
	char	*str;
	int		base_len;
	int		digits;

	if (!check_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	digits = 1;
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0 && digits++)
		n /= base_len;
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

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

int	handle_unsigned(unsigned int n)
{
	char *str;
	int len;

	str = ft_strbase(n, "0123456789");
	if (!str)
		return (-1);
	len = ft_strlen_printf(str);
	write(1, str, len);
	free(str);
	return (len);
}