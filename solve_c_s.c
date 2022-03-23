/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:06:38 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/23 11:26:04 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision_s(t_flags *info, char **str)
{
	char	*temp;

	temp = NULL;
	if (info->_type == 's')
	{
		if (info->_precision)
		{
			if (info->_precision < (int)ft_strlen(*str))
			{
				temp = ft_strnew(info->_precision);
				ft_strncpy(temp, *str, info->_precision);
				*str = temp;
				return (1);
			}
		}
		else if (!info->_precision && info->_p_true)
		{
			temp = ft_strnew(0);
			*str = temp;
			return (1);
		}
	}
	return (0);
}

static char	*ft_width_helper(t_flags *info, char *temp, char *str, int *i)
{
	if (info->_minus)
	{
		ft_strcat(temp, str);
		*i = ft_strlen(str);
		while (*i < info->_width)
		{
			if (str[0] == '\0' && *i == info->_width - 1 && info->_type == 'c')
				break ;
			temp[(*i)++] = ' ';
		}
	}
	else
	{
		ft_strcpy(&temp[info->_width - (int)ft_strlen(str)], str);
		while (*i < (info->_width - (int)ft_strlen(str)))
		{
			if (str[0] == '\0' && *i == info->_width - 1 && info->_type == 'c')
				break ;
			temp[(*i)++] = ' ';
		}
	}
	return (temp);
}

static char	*ft_width_plus(t_flags *info, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (str[0] == '\0' && info->_type == 'c')
		temp = ft_strnew(info->_width - 1);
	else
		temp = ft_strnew(info->_width);
	if (!temp)
		return (NULL);
	temp = ft_width_helper(info, temp, str, &i);
	return (temp);
}

char	*ft_solve_c_s(t_flags *info, char *str)
{
	char	*temp;

	info->_p_check = 0;
	temp = NULL;
	if (!str)
		str = "(null)";
	info->_p_check = ft_precision_s(info, &str);
	if (info->_width <= (int)ft_strlen(str))
	{
		temp = ft_strdup(str);
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = ft_width_plus(info, str);
		if (!temp)
			return (NULL);
	}
	if (info->_p_check == 1 || info->_type == 'c')
		ft_strdel(&str);
	return (temp);
}
