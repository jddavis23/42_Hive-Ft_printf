/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/24 18:12:34 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	ft_nb_lt(long long int nb, int *sign, int *count,
		int in)
{
	if (nb < 0)
	{
		*sign = -1;
		if (in == 1)
			++(*count);
		return (nb * -1);
	}
	else
		return (nb);
}

static char	*ft_extr_rtrn(long long int nb, char c, char **str)
{
	if (c == '%')
	{
		*str = ft_strdup("%");
		return (*str);
	}
	if (nb == 0)
	{
		*str = ft_strdup("0");
		//return (*str);
	}
	return (NULL);
}

static void	ft_minus(int sign, char **str)
{
	if (sign == -1)
		(*str)[0] = '-';
}

char	*ft_num_toa(long long int nb, t_flags *info, int choice)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;
	int							sign;

	sign = 1;
	str = NULL;
	count = 0;
	if (nb > 0)
		info->_gt = 1;
	else if (nb < 0)
		info->_gt = -1;
	else
		info->_gt = 0;
	if (ft_extr_rtrn(nb, info->_type, &str) || info->_type == '%') //nb, info->_type, &str))
		return (str);
	dup_nb = ft_nb_lt(nb, &sign, &count, 1);
	while (dup_nb > 0)
	{
		dup_nb /= choice;
		count++;
	}
	if (nb != 0)
	{
		str = ft_strnew(count);
		dup_nb = ft_nb_lt(nb, &sign, &count, 0);
		while (dup_nb > 0)
		{
			str[--count] = ft_char_digit((char)(dup_nb % choice), info->_type);
			dup_nb /= choice;
		}
		ft_minus(sign, &str);
	}
	if (info->_type != 'f')
		ft_precision_nb(info, &str, nb);
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
