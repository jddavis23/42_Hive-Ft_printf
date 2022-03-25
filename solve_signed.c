/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:36:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/25 18:13:25 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

static char	*ft_true_zero(t_flags *info, char *temp, char *str,
	long long int nb)
{
	int	i;

	i = 0;
	ft_apply_hash(info, nb, &temp, &i);
	if (info->_plus && nb >= 0 && info->_type != '%' && info->_type != 'X' && info->_type != 'x' && info->_type != 'u' && info->_type != 'o')
		temp[i++] = '+';
	else if (nb < 0 && info->_type != '%' && info->_type != 'X' && info->_type != 'x' && info->_type != 'u' && info->_type != 'o')
		temp[i++] = '-';
	else if (info->_space && nb >= 0 && info->_type != '%' && info->_type != 'X' && info->_type != 'x' && info->_type != 'u' && info->_type != 'o')
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
	if ((((info->_width - (int)ft_strlen(str) - info->_h_sub)) < 0)
		&& info->_hash && (info->_type == 'X' || info->_type == 'x' || info->_type == 'o'))
	{
		ft_strdel(temp);
		*temp = ft_strnew(ft_strlen(info->_h_prfx) + ft_strlen(str));
	}
	while (((i < (info->_width - (int)ft_strlen(str) - info->_h_sub)) || (nb == 0 && i < info->_width - (int)ft_strlen(str))) && (info->_type == 'X' || info->_type == 'u' || info->_type == 'x' || info->_type == 'o'))
		(*temp)[i++] = ' ';
	ft_apply_hash(info, nb, temp, &i);
	while ((i < (info->_width - (int)ft_strlen(str) - 1)))// && (info->_type != 'X' || info->_type != 'x' || info->_type != 'o' || info->_type != 'u'))
		(*temp)[i++] = ' ';
	if (info->_plus && nb >= 0 && info->_type != '%' && (info->_type != 'X' || info->_type != 'x' || info->_type != 'o' || info->_type != 'u'))
		(*temp)[i++] = '+';
	else if (info->_type != 'u' && !info->_hash) //(info->_type != 'X' && info->_type != 'x' && info->_type != 'o' && info->_type != 'u')
	{
		if ((info->_type == 'X' || info->_type == 'x' || info->_type == 'o') && nb == 0)
		   --i;	
		(*temp)[i++] = ' ';
	}
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
		ft_apply_hash(info, nb, &temp, &i);
		if (info->_plus && nb >= 0 && info->_type != '%' && (info->_type != 'X' || info->_type != 'x' || info->_type != 'u' || info->_type != 'o'))
			temp[i++] = '+';
		ft_strcpy(&temp[i], *str);
			i += ft_strlen(*str);
		while (i < info->_width)
			temp[i++] = ' ';
	}
	else if (info->_zero && (!info->_p_true || info->_type == '%' || info->_type == 'f'))// || info->_type == 'X' || info->_type == 'x' || info->_type == 'u' || info->_type == 'o'))
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

char	*ft_solve_signed(t_flags *info, char *str, long long int nb)
{
	int		i;
	char	*temp;

	i = 0;
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_true_width(info, &str, nb);
		ft_strdel(&str);
		str = temp;
	}
	else if (info->_type != 'X' && info->_type != 'x' && info->_type != 'o' && info->_type != 'u')
	{
		if (info->_type != '%' && (info->_plus || info->_space))
		str = ft_no_width(info, &str, nb);
	}
	else// if (info->_type == 'X' || info->_type == 'x' || info->_type == 'o')
	{
		//printf("%d---after\n", info->_gt);
		if (info->_hash && ((info->_gt > 0 && info->_type != 'o')
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
