/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthewjorge <matthewjorge@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:47:03 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/04/24 11:54:57 by matthewjorg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


int ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void    ft_showpointer(void*);





#endif