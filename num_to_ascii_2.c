/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:20:01 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/28 14:23:33 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prcsion_round(long long unsigned int x, char **temp, int d)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_strnew(d + 1);
	if (!str)
		return (NULL);
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i - 1 < d)
		str[i++] = '0';
	ft_strrev(str, i);
	str[i] = '\0';
	ft_strcat(*temp, str);
	ft_strdel(&str);
	return (*temp);
}

char	*ft_ftoa(t_flags *info, long double nb)
{
	char		*str;
	int			i;
	char		*temp;

	i = 0;
	str = NULL;
	temp = ft_num_toa((long long unsigned int)nb, info, 10);
	if (!temp)
		return (NULL);
	if (info->_p_true && !info->_precision)
		return (temp);
	str = ft_strnew(ft_strlen(temp) + info->_precision + 2);
	ft_strcat(ft_strcat(str, temp), ".");
	ft_strdel(&temp);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	nb = (nb - (long long unsigned int)nb);
	nb *= ft_power(10, info->_precision + 1); //Rounding solution here
	if (!ft_prcsion_round((long long unsigned int)nb, &str, info->_precision))
		return (NULL);
	ft_rounder(&str, info);
	return (str);
}

static void	ft_struct_nb(t_flags **info, unsigned long long int nb)
{
	if (nb > 0)
		(*info)->_gt = 1;
	else if (nb < 0)
		(*info)->_gt = -1;
	else
		(*info)->_gt = 0;
}

static char	*ft_nb_zero(t_flags **info, char **str)
{
	*str = ft_strdup("0");
	if (!*str)
		return (NULL);
	(*info)->_p_check = ft_precision_nb((*info), str, (*info)->_gt);
	return (*str);
}

char	*ft_llu_toa(unsigned long long int nb, t_flags **info)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;

	count = 0;
	str = NULL;
	ft_struct_nb(info, nb);
	if (nb == 0)
		return (ft_nb_zero(info, &str));
	dup_nb = nb;
	while (nb > 0)
	{
		nb /= (*info)->_div;
		count++;
	}
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((dup_nb % (*info)->_div), (*info)->_type);
		dup_nb /= (*info)->_div;
	}
	(*info)->_p_check = ft_precision_nb((*info), &str, (*info)->_gt);
	return (str);
}
