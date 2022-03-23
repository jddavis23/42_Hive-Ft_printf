/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_x_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:50:06 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/23 13:26:56 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_minus(t_flags *info, char *temp, char *str,
	long long unsigned int nb)
{
	int	i;

	i = 0;
	ft_apply_hash(info, nb, &temp, &i);
	ft_strcpy(&temp[i], str);
	i += ft_strlen(str);
	while (i < info->_width)
		temp[i++] = ' ';
	return (temp);
}

static char	*ft_width_else(t_flags *info, char *temp, char *str,
	long long unsigned int nb)
{
	int	i;

	i = 0;
	if ((((info->_width - (int)ft_strlen(str) - info->_h_sub)) < 0)
		&& info->_hash)
	{
		ft_strdel(&temp);
		temp = ft_strnew(ft_strlen(info->_h_prfx) + ft_strlen(str));
	}
	while ((i < (info->_width - (int)ft_strlen(str) - info->_h_sub))
		|| (nb == 0 && i < info->_width - (int)ft_strlen(str)))
		temp[i++] = ' ';
	ft_apply_hash(info, nb, &temp, &i);
	while (i < info->_width - (int)ft_strlen(str))
		temp[i++] = ' ';
	ft_strcpy(&temp[i], str);
	return (temp);
}

static char	*ft_width_plus(t_flags *info, long long unsigned int nb,
	char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	temp = ft_strnew(info->_width);
	if (!temp)
		return (NULL);
	if (info->_minus)
		temp = ft_minus(info, temp, str, nb);
	else if (info->_zero && !info->_p_true)
	{
		ft_apply_hash(info, nb, &temp, &i);
		while (i < info->_width - (int)ft_strlen(str))
			temp[i++] = '0';
		ft_strcpy(&temp[i], str);
	}
	else
		temp = ft_width_else(info, temp, str, nb);
	ft_strdel(&str);
	return (temp);
}

char	*ft_solve_unsigned(t_flags *info, long long unsigned int nb)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	str = ft_llu_toa(nb, info->_type, info->_div);
	info->_p_check = ft_precision_nb(info, &str, nb);
	if (info->_width > (int)ft_strlen(str))
		str = ft_width_plus(info, nb, str);
	else
	{
		if (info->_hash && ((nb > 0 && info->_type != 'o')
				|| (info->_type == 'o' && str[0] != '0')))
		{
			temp = ft_strnew(ft_strlen(str) + info->_h_sub);
			ft_strcpy(&temp[i], info->_h_prfx);
			i += ft_strlen(info->_h_prfx);
			ft_strcpy(&temp[i], str);
			ft_strdel(&str);
			str = temp;
		}
	}
	return (str);
}
