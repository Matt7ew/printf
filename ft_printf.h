/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:47:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 05:35:05 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		handle_specifier(char c, va_list args);
int		handle_char(int c);
int		handle_str(char *str);
int		handle_ptr(void *ptr);
int		handle_nbr(int n);
int		handle_hex(unsigned int n, int uppercase);
int		handle_unsigned(unsigned int n);
char	*ft_strbase(unsigned long long n, char *base);
int		ft_print_prefix(char *prefix);
int		ft_strlen_printf(const char *s);

#endif