/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/21 13:50:10 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //remove

char	*ft_num_toa(long long int nb, char c, int choice)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;
	int							sign;

	sign = 1;
	str = NULL;
	count = 0;
	if (c == '%')
	{
		str = ft_strdup("%");
		return (str);
	}
	if (nb < 0)
	{
		dup_nb = nb * -1;
		sign = -1;
		++count;
	}
	else
		dup_nb = nb;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (dup_nb > 0)
	{
		dup_nb /= choice;
		count++;
	}
	str = ft_strnew(count);
	if (nb < 0)
		dup_nb = nb * -1;
	else
		dup_nb = nb;
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((char)(dup_nb % choice), c);
		dup_nb /= choice;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_llu_toa(unsigned long long int nb, char c, int choice)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;

	count = 0;
	str = NULL;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	dup_nb = nb;
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
	return (str);
}
