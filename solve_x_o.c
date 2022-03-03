/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_x_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:50:06 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/03 12:32:11 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*ft_num_toa(unsigned int nb, char c, int choice)
{
	int		count = 0;
	char	*str;
	int		dup_nb;

	dup_nb = nb;
	str = NULL;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (nb > 0)
	{
		nb /= choice;
		count++;
	}
	str = ft_strnew(count);
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit(dup_nb % choice, c);
		dup_nb /= choice;
	}
	return (str);
}*/

/*void	ft_apply_hash(t_flags *info, unsigned int nb, int checker, char **temp, int *i)
{
	if (info->_hash && nb != 0 && (!checker || info->_type != 'o'))
	{
		ft_strcpy(&(*temp)[*i], info->_h_prfx);
		*i += ft_strlen(info->_h_prfx);
	}
}*/

char	*ft_width_plus(t_flags *info, unsigned int nb, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strnew(info->_width);
	if (!temp)
		return (NULL); //do you want to delete str here or not
	if (info->_minus)
	{
		ft_apply_hash(info, nb, &temp, &i);
		ft_strcpy(&temp[i], str);
		i += ft_strlen(str);
		while (i < info->_width)
			temp[i++] = ' ';
	}
	else if (info->_zero && !info->_p_true)
	{
		ft_apply_hash(info, nb, &temp, &i);
		while (i < info->_width - (int)ft_strlen(str))
			temp[i++] = '0';
		ft_strcpy(&temp[i], str);
	}
	else
	{
		if ((((info->_width - (int)ft_strlen(str) - info->_h_sub)) < 0) && info->_hash)// && nb != 0 && info->_type != 'o')
		{
			ft_strdel(&temp);
			temp = ft_strnew(2 + ft_strlen(str));
		}
		while ((i < (info->_width - (int)ft_strlen(str) - info->_h_sub)) || (nb == 0 && i < info->_width - 1))
			temp[i++] = ' ';
		ft_apply_hash(info, nb, &temp, &i);
		while (i < info->_width - (int)ft_strlen(str))
			temp[i++] = ' ';
		if (nb == 0 && !info->_precision && info->_p_true)
			temp[i] = ' ';
		else	
			ft_strcpy(&temp[i], str);
	}
	ft_strdel(&str);
	return (temp);
}

char	*ft_solve_o_x(t_flags *info, unsigned int nb)
{
	char	*str;
	char	*temp;
	int		i;
	
	i = 0;
	temp = NULL;
	str = ft_num_toa(nb, info->_type, info->_div);
	info->_p_check = ft_precision_nb(info, &str);
	if (info->_width > (int)ft_strlen(str))
	{

		/*temp = ft_strnew(info->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_minus)
		{
			if (info->_hash && nb != 0 && (!checker || info->_type != 'o'))
			{
				ft_strcpy(&temp[i], info->_h_prfx);
				i += ft_strlen(info->_h_prfx);
			}
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->_p_true)
		{
			if (info->_hash && nb != 0 && (info->_type != 'o' || !checker))
			{
				ft_strcpy(&temp[i], info->_h_prfx);
				i += ft_strlen(info->_h_prfx);
			}
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			if ((((info->_width - (int)ft_strlen(str) - sub)) < 0) && info->_hash && nb != 0 && info->_type != 'o')
			{
				ft_strdel(&temp);
				temp = ft_strnew(2 + ft_strlen(str));
			}
			while ((i < (info->_width - (int)ft_strlen(str) - sub)) || (nb == 0 && i < info->_width - 1))
				temp[i++] = ' ';
			if (info->_hash && nb != 0 && (info->_type != 'o' || !checker))
			{
				ft_strcpy(&temp[i], info->_h_prfx);
				i += ft_strlen(info->_h_prfx);
			}
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = ' ';
			if (nb == 0 && !info->_precision && info->_p_true)
				temp[i] = ' ';
			else	
				ft_strcpy(&temp[i], str);
		}*/
		//ft_strdel(&str);
		str = ft_width_plus(info, nb, str);
	}
	else
	{
		if (info->_hash && nb != 0) //change here
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
