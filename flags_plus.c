/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:31:58 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/02 11:32:56 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_nb(t_flags *info, char **str)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (info->_precision > (int)ft_strlen(*str))
	{
		temp = ft_strnew(info->_precision);
		if (!temp)
			return (-1);
		while (i < (info->_precision - (int)ft_strlen(*str)))
			temp[i++] = '0';
		ft_strcpy(&temp[i], *str);
		ft_strdel(str);
		*str = temp;
		return (1);
	}
	return (0);
}
