/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:20:01 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/24 18:44:03 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

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
	nb *= ft_power(10, info->_precision + 1);
	if (!ft_prcsion_round((long long unsigned int)nb, &str, info->_precision))
		return (NULL);
	ft_rounder(&str, info);
	return (str);
}
