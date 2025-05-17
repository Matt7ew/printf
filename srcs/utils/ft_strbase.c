/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:06:45 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 07:51:51 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 07:06:45 by mjorge            #+#    #+#             */
/*   Updated: 2025/05/17 07:37:44 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
	char				*str;
	int					base_len;
	int					digits;
	unsigned long long	temp;

	if (!check_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	digits = 0;
	temp = n;
	if (temp == 0)
		digits = 1;
	while (temp > 0)
	{
		temp /= base_len;
		digits++;
	}
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == 0)
		str[0] = base[0];
	while (n > 0)
	{
		str[--digits] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
