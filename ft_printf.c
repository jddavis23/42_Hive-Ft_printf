/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:34:24 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/22 13:00:03 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_c_or_s(t_flags *info, va_list *ap)
{
	char	*c_pass;
	char	*str;

	c_pass = NULL;
	str = NULL;
	if (info->_type == 's')
		str = ft_solve_c_s(info, va_arg(*ap, char *));
	else
	{
		c_pass = ft_strnew(1);
		if (!c_pass)
			return (NULL);
		c_pass[0] = (char)va_arg(*ap, int);
		str = ft_solve_c_s(info, c_pass);
		if (c_pass[0] == '\0')
			++info->_ret;
	}
	return (str);
}

int	ft_solve(va_list *ap, t_flags *info)
{
	char	*str;
	char	*c_pass;

	str = NULL;
	c_pass = NULL;
	if (info->_type == 'c' || info->_type == 's')
		str = ft_c_or_s(info, ap);
	else if (info->_type == 'u' || info->_type == 'x'
		|| info->_type == 'X' || info->_type == 'o')
		str = ft_choice_unsigned(info, ap);
	else if (info->_type == 'd' || info->_type == 'i')
		str = ft_choice_signed(info, ap);
	else if (info->_type == 'p')
		str = ft_solve_p(info, va_arg(*ap, uintptr_t));
	else if (info->_type == 'f')
		str = ft_choice_f(info, ap);
	else if (info->_type == '%')
		str = ft_solve_signed(info, 0);
	if (!str)
		return (-1);
	info->_ret += write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (1);
}

static int	ft_prnt_type(t_flags *info, const char *format, va_list *ap, int *a)
{
	++(*a);
	info = ft_true_struct(info, format, a);
	if (!info)
		return (-1);
	if (ft_solve(ap, info) == -1)
	{
		free(info);
		return (-1);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		a;
	t_flags	*info;

	a = 0;
	info = ft_create_struct(NULL);
	if (!info)
		return (-1);
	va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			if (ft_prnt_type(info, format, &ap, &a) == -1)
				return (-1);
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
