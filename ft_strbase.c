/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:30:07 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 03:04:55 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(const char *base)
{
	if (!base)
		return (0);
	if (ft_strlen(base) < 2 || !ft_str_unique((char *)base))
		return (0);
	return (1);
}

static int	get_rlength(unsigned long long input, const char *base)
{
	int	length;
	int	base_len;

	base_len = ft_strlen(base);
	length = 0;
	if (input == 0)
		return (1);
	while (input != 0)
	{
		input = input / base_len;
		length++;
	}
	return (length);
}

char	*ft_strbase(unsigned long long input, const char *base)
{
	char	*result;
	int		length;
	int		base_len;

	if (!check_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	length = get_rlength(input, base);
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (input == 0)
		result[0] = base[0];
	else
	{
		while (input != 0)
		{
			length--;
			result[length] = base[input % base_len];
			input = input / base_len;
		}
	}
	return (result);
}

int	handle_u(unsigned int num)
{
	char	*str;

	str = ft_strbase(num, "0123456789");
}

int	handle_d_i(int num)
{
	int					sign;
	unsigned long long	abs_num;
	char				*str;

	sign = 1;
	if (num < 0)
	{
		sign = -1;
		abs_num = (unsigned long long)(-num);
	}
	else
	{
		abs_num = num;
	}
	str = ft_strbase(abs_num, "0123456789");
}
