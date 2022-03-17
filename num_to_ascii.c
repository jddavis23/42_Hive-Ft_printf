/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/17 17:04:07 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //remove

char	*ft_num_toa(long long int nb, char c, int choice)
{
	int		count = 0;
	char	*str;
	long long int		dup_nb;
	int		sign;

	sign = 1;
	str = NULL;
	if (c == '%')
	{
		str = ft_strdup("%");
		return (str);
	}
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
		++count;
	}
	dup_nb = nb;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (nb > 0)
	{
		nb /= choice;
		count++;
	}
	str = ft_strnew(count);
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((char)(dup_nb % choice), c);
		dup_nb /= choice;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
