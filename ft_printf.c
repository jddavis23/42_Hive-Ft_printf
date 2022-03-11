/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/11 16:33:42 by jdavis           ###   ########.fr       */
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

		if (forma[i + 1] == '%' || forma[i + 1] == '\0')
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


t_flags	*ft_true_struct(t_flags *info, char *str, char type)
{
	int	i = 0;
	
	info = ft_create_struct(info);
	if (!info)
		return (NULL);
	info->_type = type;
	while (str[i] == '0' || str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '#')
	{
		if (str[i] == '0' && info->_minus == 0)
		   info->_zero = 1;	
		if (str[i] == '#')
		   info->_hash = 1;	
		if (str[i] == ' ' && info->_plus == 0)
		   info->_space = 1;
		if (str[i] == '-')
		{
			info->_zero = 0;
			info->_minus = 1;
		}	
		if (str[i] == '+')
		{
			info->_space = 0;
			info->_plus = 1;
		}
		++i;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		info->_width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == '.')
	{
		info->_p_true = 1;
		++i;
		info->_precision = ft_atoi(&str[i]); //change _p_true to only be true if ft_atoi is zero but '.' is present
		//if (!info->_precision)
		//	info->_p_true = 1;
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == 'h' || str[i] == 'l')
	{
		if (str[i] == 'h' && str[i + 1] == type)
			info->_h = 1;
		else if (str[i] == 'l' && str[i + 1] == type)
			info->_l = 1;
		else if (str[i] == 'h' && str[i + 1] == 'h')
			info->_hh = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
			info->_ll = 1;
	}
	ft_bzero(info->_h_prfx, 3);
	if (type == 'x' || type == 'X' || type == 'p')
	{
		info->_div = 16;
		info->_h_sub = 2;
		info->_h_prfx[0] = '0';
		if (type == 'p')
			info->_h_prfx[1] = 'x';
		else
			info->_h_prfx[1] = type;
	}
	else if (type == 'o')
	{
		info->_div = 8;
		info->_h_sub = 1;
		info->_h_prfx[0] = '0';
	}
	else
		info->_div = 10;
	return (info);
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
	ft_strdel(&str);   //isnt working how i thought it would
	return (info);
}

long long int	ft_power(double nb, int power)
{
	long long int  result;

	result = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power >= 0)
	{
		while (power >= 1)
		{
			result *= nb;
			--power;
		}
	}
	return (result);
}

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

char	*ft_floating(t_flags *info, double nb)
{
	char		*str;
	int			i;
	char		*temp;
	char		*full;
	
	i = 0;
	str = NULL;
	temp = ft_num_toa((long long int)nb, info->_type, 10);
	if (!temp)
		return (NULL);
	str = ft_strjoin(temp, ".");
	ft_strdel(&temp);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	nb = (nb - (long long)nb);
	nb += 1;
	nb *= ft_power(10, 18);  //should be dependent on precision
	temp = ft_num_toa((long long int)nb, info->_type, 10);
	if (!temp)
		return (NULL);
	full = ft_strjoin(str, &temp[1]);
	ft_strdel(&temp);
	if (!full)
		return (NULL);
	ft_rounder(&full, info);
	return (full);
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
	return (str);
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
		str = ft_solve_f(info, (double)va_arg(*ap, double)); //only works with floats. look into doubles!
	else if (info->_type == '%')
		str = ft_strdup("%");
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
			//if (!str)
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
		}
		else
		{
			info->_ret += write(1, &format[a], ft_strlen_stop(&format[a], '%'));
			a += ft_strlen_stop(&format[a], '%');
		}
	}
	va_end(ap);
	return (info->_ret);
}

