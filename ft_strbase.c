/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:30:07 by matthewjorg       #+#    #+#             */
/*   Updated: 2025/05/17 01:53:39 by mjorge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_base(const char *base)
{
    if (!base)
        return(0);
    if (ft_strlen(base) < 2 || !ft_str_unique((char*)base))
        return (0);
    return(1);
}

static get_rlength(unsigned long long int input, unsigned char *base)
{
    int length;

    length = 1;
    while(input != 0)
    {
        input = input / ft_strlen(base);
        length++;
    }
    return(length);
}

char ft_strbase(unsigned long long input, const char *base)
{
    int length;
    char    *result;

    if (!check_base(base))
        return(NULL);
    length = get_rlength(input,base);
    result = ft_calloc(length + 1, sizeof(char));
    if(!result)
        return(NULL);
    result[length] = '\0';
    length--;
    if (input == 0)
    {
        result[length] = base[length];
        return (result);
    }
    while (length > 0)
    {
        length--;
        result[length] = base[input % ft_strlen(base)];
        input = input / ft_strlen(base);
    }
    return(result);
}
int handle_d_i(int num)  
{  
    int sign = 1;  
    unsigned long long abs_num;  

    if (num < 0) {  
        sign = -1;  
        abs_num = (unsigned long long)(-num); // Safely negate  
    } else {  
        abs_num = num;  
    }  

    char *str = ft_strbase(abs_num, "0123456789");  
    // Print sign (if needed) + str  
}  