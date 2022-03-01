/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:06:38 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/01 17:07:05 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_solve_c_s(t_flags *info, char *str)
{
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	checker = 0;
	temp = NULL;
	if (info->_type == 's')
	{
		if (info->_precision)
		{
			if (info->_precision < (int)ft_strlen(str))
			{
				checker = 1;
				temp = ft_strnew(info->_precision);
				ft_strncpy(temp, str, info->_precision);
				str = temp;
			}
		}
	}
	if (info->_width <= (int)ft_strlen(str))
	{
		temp = ft_strdup(str);
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = ft_strnew(info->_width);
		if (!temp)
			return (NULL);
		if (info->_minus)
		{
			ft_strcat(temp, str);
			i = ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else
		{
			ft_strcpy(&temp[info->_width - (int)ft_strlen(str)], str);
			while (i < (info->_width - (int)ft_strlen(str)))
				temp[i++] = ' ';
		}
	}
	if (checker == 1 || info->_type == 'c')
		ft_strdel(&str);
	return (temp);
}
