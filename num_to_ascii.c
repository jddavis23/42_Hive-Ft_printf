/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/03 12:43:50 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_num_toa(long long nb, char c, int choice)
{
	int		count = 0;
	char	*str;
	int		dup_nb;
	int		sign;

	sign = 1;
	dup_nb = nb;
	str = NULL;
	if (nb < 0)
	{
		sign = -1;
		++count;
	}
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
		str[--count] = ft_char_digit(dup_nb % choice, c);
		dup_nb /= choice;
	}
	return (str);
}
