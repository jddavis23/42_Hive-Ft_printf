/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:36:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/15 13:57:41 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

/*char	*ft_solve_d_i_u(t_flags *info, int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	temp = NULL;
	str = ft_itoa(nb);
	checker = ft_precision_nb(info, &str);
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		else if (info->_space && nb >= 0)
			temp[i++] = ' ';
		if (info->_minus)
		{
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->_p_true)
		{
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			while (i < (info->_width - (int)ft_strlen(str)))
				temp[i++] = ' ';
			if (nb == 0 && !info->_precision && info->_p_true)
				temp[i] = ' ';
			else	
				ft_strcpy(&temp[i], str);
		}
		ft_strdel(&str);
		str = temp;
	}
	else if (info->_plus || info->_space)
	{
		temp = ft_strnew(ft_strlen(str) + 1);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		else if (info->_space && nb >= 0)
			temp[i++] = ' ';
		ft_strcpy(&temp[i], str);
		ft_strdel(&str);
		str = temp;
	}
	return (str);
}*/

static void ft_width_else(t_flags *info, char **temp, int nb, char *str)
{
	int		i;
	//char	temp;

	i = 0;
	//temp = NULL;
	while (i < (info->_width - (int)ft_strlen(str) - 1))
		(*temp)[i++] = ' ';
	if (info->_plus && nb >= 0)
		(*temp)[i++] = '+';
	else
		(*temp)[i++] = ' ';
	ft_strcpy(&((*temp)[i]), str);
}

char	*ft_solve_d_i(t_flags *info, int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	temp = NULL;
	str = ft_itoa(nb);
	checker = ft_precision_nb(info, &str, nb);
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_minus)
		{
			if (info->_plus && nb >= 0)
				temp[i++] = '+';
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && (!info->_p_true || info->_type == 'f'))
		{
			if (info->_plus && nb >= 0)
				temp[i++] = '+';
			else if (nb < 0)
				temp[i++] = '-';
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			if (nb < 0)
			{
				temp[i++] = '0';
				ft_strcpy(&temp[i], &str[1]);
			}
			else
				ft_strcpy(&temp[i], str);
		}
		else
			ft_width_else(info, &temp, nb, str);
		ft_strdel(&str);
		str = temp;
	}
	else if (info->_plus || info->_space)
	{
		temp = ft_strnew(ft_strlen(str) + 1);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		else if (info->_space && nb >= 0)
			temp[i++] = ' ';
		ft_strcpy(&temp[i], str);
		ft_strdel(&str);
		str = temp;
	}
	return (str);
}
