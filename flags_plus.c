/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:31:58 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/15 13:31:54 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_hash(t_flags *info, unsigned int nb, char **temp, int *i)
{
	if (info->_hash && nb != 0 && (!info->_p_check || info->_type != 'o'))
	{
		ft_strcpy(&(*temp)[*i], info->_h_prfx);
		*i += ft_strlen(info->_h_prfx);
	}
}

int	ft_precision_nb(t_flags *info, char **str, long long  int nb)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	//ft_putstr("here\n");
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
	else if (!info->_precision && info->_p_true && nb == 0)
	{
		ft_strdel(str);
		*str = ft_strnew(1);
	}
	return (0);
}
