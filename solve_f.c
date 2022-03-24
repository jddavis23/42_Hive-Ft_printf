/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:49 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/24 13:10:15 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

static void	ft_width_else(t_flags *info, char **temp, int nb, char *str)
{
	int		i;

	i = 0;
	while (i < (info->_width - (int)ft_strlen(str) - 1))
		(*temp)[i++] = ' ';
	if (info->_plus && nb >= 0)
		(*temp)[i++] = '+';
	else
		(*temp)[i++] = ' ';
	if (nb == 0 && !info->_precision && info->_p_true)
		(*temp)[i] = ' ';
	else
		ft_strcpy(&((*temp)[i]), str);
}

static void	ft_width_else_if(t_flags *info, long double nb, char *str,
	char **temp)
{
	int	i;

	i = 0;
	if (info->_plus && nb >= 0)
		(*temp)[i++] = '+';
	else if (nb < 0)
		(*temp)[i++] = '-';
	else if (info->_space && nb >= 0)
		(*temp)[i++] = ' ';
	while (i < info->_width - (int)ft_strlen(str))
		(*temp)[i++] = '0';
	if (nb < 0)
	{
		(*temp)[i++] = '0';
		ft_strcpy(&((*temp)[i]), &(str[1]));
	}
	else
		ft_strcpy(&((*temp)[i]), str);
}

static char	*ft_width(t_flags *info, char **str, long double nb, int i)
{
	char	*temp;

	temp = ft_strnew(info->_width);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	if (info->_minus)
	{
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		ft_strcpy(&temp[i], *str);
		i += ft_strlen(*str);
		while (i < info->_width)
			temp[i++] = ' ';
	}
	else if (info->_zero && (!info->_p_true || info->_type == 'f'))
		ft_width_else_if(info, nb, *str, &temp);
	else
		ft_width_else(info, &temp, nb, *str);
	ft_strdel(str);
	*str = temp;
	return (*str);
}

static void	ft_else_if(t_flags *info, long double nb, char **str, char **temp)
{
	int	i;

	i = 0;
	if (info->_plus && nb >= 0)
		(*temp)[i++] = '+';
	else if (info->_space && nb >= 0)
		(*temp)[i++] = ' ';
	ft_strcpy(&((*temp)[i]), *str);
	ft_strdel(str);
	*str = *temp;
}

char	*ft_solve_f(t_flags *info, long double nb)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	str = ft_ftoa(info, nb);
	if (!str)
		return (NULL);
	if (info->_width > (int)ft_strlen(str))
		temp = ft_width(info, &str, nb, i);
	else if (info->_plus || info->_space)
	{
		temp = ft_strnew(ft_strlen(str) + 1);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		ft_else_if(info, nb, &str, &temp);
	}
	return (str);
}
