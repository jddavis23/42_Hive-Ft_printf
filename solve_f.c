/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:49 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/17 12:11:57 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rounder(char **str, t_flags *info)
{
	int	i;
	int	carry;

	carry = 0;
	i = ft_strlen_stop(*str, '.') + info->_precision;
	if ((*str)[i + 1] >= '5')
	{
		if ((*str)[i] < '9')
			(*str)[i] += 1;
		else
		{
			(*str)[i] = '0';
			carry = 1;
		}
	}
	(*str)[i + 1] = '\0';
	while (--i >= 0)
	{
		if (carry && (*str)[i] != '.')
		{
			if ((*str)[i] < '9')
				(*str)[i] += 1;
			else
			{
				(*str)[i] = '0';
				carry = 1;
			}
		}
	}
}

int intToStr(long long unsigned int x, char str[], int d)
{
    int i;
   
	i = 0;
    while (x)
	{
        str[i++] = (x % 10) + '0';
        x /= 10;
    }
    while (i - 1 < d)
        str[i++] = '0';
  
    ft_strrev(str, i);
    str[i] = '\0';
    return i;
}

char	*ft_floating(t_flags *info, double nb)
{
	char		*str;
	int			i;
	char		*temp;
	
	i = 0;
	str = NULL;
	temp = ft_num_toa((long long unsigned int)nb, info->_type, 10);
	if (info->_p_true && !info->_precision)
		return (temp);
	if (!temp)
		return (NULL);
	str = ft_strjoin(temp, ".");
	ft_strdel(&temp);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	nb = (nb - (long long unsigned int)nb);
	if (!info->_p_true && !info->_precision)
		info->_precision = 6;
	nb *= ft_power(10, info->_precision + 1);	//should be dependent on precision
	temp = ft_strnew(ft_strlen(str) + info->_precision);
	if (!temp)
		return (NULL);
	ft_strcat(temp, str);
	//str = ft_num_toa(  test which is more precise
	intToStr((long long unsigned int)nb, &temp[ft_strlen(str)], info->_precision);
	ft_rounder(&temp, info);
	ft_strdel(&str);
	return (temp);
}

//combine solving function using function pointer

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
	if (nb == 0 && !info->_precision && info->_p_true)
		(*temp)[i] = ' ';
	else	
		ft_strcpy(&((*temp)[i]), str);
}

char	*ft_solve_f(t_flags *info, long double nb)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	str = NULL;
	str = ft_floating(info, nb);
	if (!str)
		return (NULL);
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
			else if (info->_space && nb >= 0)
				temp[i++] = ' ';
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
