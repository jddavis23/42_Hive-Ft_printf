/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:36:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/23 12:40:25 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

static char	*ft_true_zero(t_flags *info, char *temp, char *str,
	long long int nb)
{
	int	i;

	i = 0;
	if (info->_plus && nb >= 0 && info->_type != '%')
		temp[i++] = '+';
	else if (nb < 0)
		temp[i++] = '-';
	else if (info->_space && nb >= 0)
		temp[i++] = ' ';
	while (i < info->_width - (int)ft_strlen(str))
		temp[i++] = '0';
	if (nb < 0)
	{
		temp[i++] = '0';
		ft_strcpy(&temp[i], &(str[1]));
	}
	else
		ft_strcpy(&temp[i], str);
	return (temp);
}

static void	ft_width_else(t_flags *info, char **temp, int nb, char *str)
{
	int		i;

	i = 0;
	while (i < (info->_width - (int)ft_strlen(str) - 1))
		(*temp)[i++] = ' ';
	if (info->_plus && nb >= 0 && info->_type != '%')
		(*temp)[i++] = '+';
	else
		(*temp)[i++] = ' ';
	ft_strcpy(&((*temp)[i]), str);
}

static char	*ft_true_width(t_flags *info, char **str, long long int nb)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	temp = ft_strnew(info->_width);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	if (info->_minus)
	{
		if (info->_plus && nb >= 0 && info->_type != '%')
			temp[i++] = '+';
		ft_strcpy(&temp[i], *str);
			i += ft_strlen(*str);
		while (i < info->_width)
			temp[i++] = ' ';
	}
	else if (info->_zero && (!info->_p_true || info->_type == '%'))
		temp = ft_true_zero(info, temp, *str, nb);
	else
		ft_width_else(info, &temp, nb, *str);
	return (temp);
}

static char	*ft_no_width(t_flags *info, char **str, long long int nb)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	temp = ft_strnew(ft_strlen(*str) + 1);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	if (info->_plus && nb >= 0)
		temp[i++] = '+';
	else if (info->_space && nb >= 0)
		temp[i++] = ' ';
	ft_strcpy(&temp[i], *str);
	ft_strdel(str);
	*str = temp;
	return (*str);
}

char	*ft_solve_signed(t_flags *info, long long int nb)
{
	char	*str;
	int		i;
	char	*temp;

	i = 0;
	if (info->_type == '%')
		str = ft_num_toa(nb, info->_type, 0);
	else
	{
		str = ft_num_toa(nb, info->_type, 10);
		ft_precision_nb(info, &str, nb);
	}
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_true_width(info, &str, nb);
		ft_strdel(&str);
		str = temp;
	}
	else if (info->_type != '%' && (info->_plus || info->_space))
		str = ft_no_width(info, &str, nb);
	return (str);
}
