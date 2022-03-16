/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/16 11:38:35 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  //REMOVE

int	ft_is_type(char c)
{
	if (c != 'd' && c != 'i' && c != 'o' &&
			c != 'u' && c != 'x' && c != 'X' &&
			c != 'c' && c != 's' && c != 'p' &&
			c != 'f' && c != '%')
		return (1);
	return (-1);
}

int	ft_sequence(char *str)
{
	int i = 0;

	while (str[i] == '0' || str[i] == '#' || str[i] == '-' || str[i] == '+' ||
		   	str[i] == ' ')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	if (str[i] == '.')
	{
		++i;
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == 'h' && str[i + 1] != 'h')
		++i;
	else if (str[i] == 'l' && str[i + 1] != 'l')
		++i;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		i += 2;
	else if (str[i] == 'h' && str[i + 1] == 'h')
		i += 2;
	if (ft_is_type(str[i]) == 1)
		return (-1);
	return (1);
}
		
int	ft_type_plus(const char *forma, char **type_plus)
{
	int i = 0;

	if (forma[0] == '%')  //find out what this is for 
	{
		*type_plus = ft_strdup("%");
		if (!*type_plus)
			return (-1);
		return (1);
	}
	while (ft_is_type(forma[i]) == 1)
	{
		if (forma[i + 1] == '\0')
			return (-1);
		++i;
	}
	*type_plus = ft_strnew(++i);
	if (!*type_plus)
		return (-1);
	ft_strncpy(*type_plus, forma, i);
	return (i);
}

t_flags	*ft_create_struct(t_flags *in_flags)
{
	if (!in_flags)
	{
		in_flags = (t_flags *) malloc(sizeof(t_flags));
		if (!in_flags)
			return (NULL);
		in_flags->_ret = 0;
	}
	in_flags->_space = 0;
	in_flags->_zero = 0;
	in_flags->_minus = 0;
	in_flags->_plus = 0;
	in_flags->_hash = 0;
	in_flags->_h_sub = 0;
	in_flags->_div = 0;
	in_flags->_width = 0;
	in_flags->_precision = 0;
	in_flags->_p_true = 0;
	in_flags->_p_check = 0;
	in_flags->_hh = 0;
	in_flags->_h = 0;
	in_flags->_ll = 0;
	in_flags->_l = 0;
	return (in_flags);
}

int	ft_c_behaviour(t_flags *info)
{
	if (info->_zero == 1)
		return (-1);
	if (info->_plus == 1)
		return (-1);
	if (info->_space == 1)
		return (-1);
	if (info->_hash == 1)
		return (-1);
	if (info->_precision > 0)
		return (-1);
	if (info->_ll == 1)
		return (-1);
	if (info->_hh == 1)
		return (-1);
	if (info->_h == 1)
		return (-1);
	return (1);
}


int	ft_s_behaviour(t_flags *info)
{
	if (info->_zero == 1)
		return (-1);
	if (info->_plus == 1)
		return (-1);
	if (info->_space == 1)
		return (-1);
	if (info->_hash == 1)
		return (-1);
	if (info->_ll == 1)
		return (-1);
	if (info->_hh == 1)
		return (-1);
	if (info->_h == 1)
		return (-1);
	return (1);
}


int	ft_p_behaviour(t_flags *info)
{
	if (info->_zero == 1)
		return (-1);
	if (info->_plus == 1)
		return (-1);
	if (info->_space == 1)
		return (-1);
	if (info->_hash == 1)
		return (-1);
	if (info->_precision > 0)
		return (-1);
	if (info->_ll == 1)
		return (-1);
	if (info->_hh == 1)
		return (-1);
	if (info->_h == 1)
		return (-1);
	if (info->_l == 1)
		return (-1);
	return (1);
}

t_flags	*ft_do(t_flags *info, char *str)
{
	info = ft_true_struct(info,str, str[ft_strlen(str) - 1]);
	/*if (str[ft_strlen(str) - 1] == 'c')
	{
		if (f_array[0](info) == -1)
			return (NULL);
	}
	if (str[ft_strlen(str) - 1] == 's')
	{
		if (f_array[1](info) == -1)
			return (NULL);
	}
	if (str[ft_strlen(str) - 1] == 'p')
	{
		if (f_array[2](info) == -1)
			return (NULL);
	}*/
	//ft_strdel(&str);   //isnt working how i thought it would
	return (info);
}

int	ft_solve(va_list *ap, t_flags *info)
{
	char	*str;
	char	*c_pass;

	str = NULL;
	c_pass = NULL;
	if (info->_type == 'c' || info->_type == 's')
	{
		if (info->_type == 's')
			str = ft_solve_c_s(info, va_arg(*ap, char*));
		else
		{
			c_pass = ft_strnew(1);
			c_pass[0] = (char)va_arg(*ap, int); //maybe change c_pass into fixed size array
			str = ft_solve_c_s(info, c_pass);
		}
	}
	else if (info->_type =='x' || info->_type == 'X' || info->_type == 'o')
		str = ft_solve_o_x(info, va_arg(*ap, unsigned int));
	else if (info->_type == 'd' || info->_type == 'i')
		str = ft_solve_d_i(info, va_arg(*ap, int));
	else if (info->_type == 'u')
		str = ft_solve_u(info, va_arg(*ap, long long));
	else if (info->_type == 'p')
		str = ft_solve_p(info, va_arg(*ap, uintptr_t));
	else if (info->_type == 'f')
		str = ft_solve_f(info, (double)va_arg(*ap, double)); //doesnt work with max flaot. look into doubles!
	else if (info->_type == '%')
		str = ft_solve_d_i(info, 0);
	if (!str)
		return (-1);
	info->_ret += write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		a = 0;
	char	*str;
	t_flags	*info;

	str = NULL;
	info = ft_create_struct(NULL);
	if (!info)
		return (-1);
	va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			++a;
			a+= ft_type_plus(&format[a], &str);
			if (!str)
				return (-1);
				//delete info
			if (ft_sequence(str) == -1)
			{
				ft_strdel(&str);
				return (-1);
			}
			info = ft_do(info, str);
			if (!info)
				return (-1);
			if (ft_solve(&ap, info) == -1)
				return (-1);
			ft_strdel(&str);   //isnt working how i thought it would
		}
		else
		{
			info->_ret += write(1, &format[a], ft_strlen_stop(&format[a], '%'));
			a += ft_strlen_stop(&format[a], '%');
		}
	}
	va_end(ap);
	free(info);
	return (info->_ret);
}

