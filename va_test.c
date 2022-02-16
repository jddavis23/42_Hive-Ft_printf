/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/16 18:12:47 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_is_type(char c)
{
	if (c != 'd' && c != 'i' && c != 'o' &&
			c != 'u' && c != 'x' && c != 'X' &&
			c != 'c' && c != 's' && c != 'p' &&
			c != 'f')
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

	if (forma[0] == '%')
	{
		*type_plus = ft_strdup("%");
		return (1);
	}
	while (ft_is_type(forma[i]) == 1)
	{

		if (forma[i + 1] == '%' || forma[i + 1] == '\0')
			return (-1);
		++i;
	}
	*type_plus = ft_strnew(i + 1);
	ft_strncpy(*type_plus, forma, i);
	(*type_plus)[i] = forma[i];
	return (i);
}

t_flags	*ft_create_struct(void)
{
	t_flags		*in_flags;
	t_width		*in_width;
	t_precision	*in_precision;
	t_length	*in_length;

	in_flags = (t_flags *) malloc(sizeof(t_flags));
	in_flags->_space = 0;
	in_flags->_zero = 0;
	in_flags->_minus = 0;
	in_flags->_plus = 0;
	in_flags->_hash = 0;
	in_width = (t_width *) malloc(sizeof(t_width));
	in_width->_width = 0;
	in_precision = (t_precision *) malloc(sizeof(t_precision));
	in_precision->_precision = 0;
	in_length = (t_length *) malloc(sizeof(t_length));
	in_length->_hh = 0;
	in_length->_h = 0;
	in_length->_ll = 0;
	in_length->_l = 0;
	in_flags->next = in_width;
	in_width->next = in_precision;
	in_precision->next = in_length;
	return (in_flags);
}


t_flags	*ft_true_struct(char *str, char type)
{
	int	i = 0;
	t_flags *info;
	
	info = ft_create_struct();
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
		info->next->_width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == '.')
	{
		++i;
		info->next->next->_precision = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == 'h' || str[i] == 'l')
	{
		if (str[i] == 'h' && str[i + 1] == type)
			info->next->next->next->_h = 1;
		else if (str[i] == 'l' && str[i + 1] == type)
			info->next->next->next->_l = 1;
		else if (str[i] == 'h' && str[i + 1] == 'h')
			info->next->next->next->_hh = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
			info->next->next->next->_ll = 1;
	}
	return (info);
	/*ft_putstr("_space = ");
	ft_putnbr(info->_space);
	ft_putchar('\n');
	ft_putstr("_minus = ");
	ft_putnbr(info->_minus);
	ft_putchar('\n');
	ft_putstr("_plus = ");
	ft_putnbr(info->_plus);
	ft_putchar('\n');
	ft_putstr("_hash = ");
	ft_putnbr(info->_hash);
	ft_putchar('\n');
	ft_putstr("_zero = ");
	ft_putnbr(info->_zero);
	ft_putchar('\n');
	ft_putstr("_width = ");
	ft_putnbr(info->next->_width);
	ft_putchar('\n');
	ft_putstr("_precision = ");
	ft_putnbr(info->next->next->_precision);
	ft_putchar('\n');
	ft_putstr("_hh = ");
	ft_putnbr(info->next->next->next->_hh);
	ft_putchar('\n');
	ft_putstr("_ll = ");
	ft_putnbr(info->next->next->next->_ll);
	ft_putchar('\n');
	ft_putstr("_l = ");
	ft_putnbr(info->next->next->next->_l);
	ft_putchar('\n');
	ft_putstr("_h = ");
	ft_putnbr(info->next->next->next->_h);
	ft_putchar('\n');
	ft_putstr("type specifier = ");
	ft_putchar(type);
	ft_putchar('\n');*/
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
	if (info->next->next->_precision > 0)
		return (-1);
	if (info->next->next->next->_ll == 1)
		return (-1);
	if (info->next->next->next->_hh == 1)
		return (-1);
	if (info->next->next->next->_h == 1)
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
	if (info->next->next->next->_ll == 1)
		return (-1);
	if (info->next->next->next->_hh == 1)
		return (-1);
	if (info->next->next->next->_h == 1)
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
	if (info->next->next->_precision > 0)
		return (-1);
	if (info->next->next->next->_ll == 1)
		return (-1);
	if (info->next->next->next->_hh == 1)
		return (-1);
	if (info->next->next->next->_h == 1)
		return (-1);
	if (info->next->next->next->_l == 1)
		return (-1);
	return (1);
}


t_flags	*ft_do(char *str)
{
	t_flags *info;

	info = ft_true_struct(str, str[ft_strlen(str) - 1]);
	if (str[ft_strlen(str) - 1] == 'c')
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
	}
	ft_strdel(&str);
	return (info);
}

int	va_test(const char *format, ...)
{
	va_list ap;
	int		a = 0;
	int		b = 0;
	char	buff[100];
	char	*str;
	char	*temp;
	t_flags	*info;
	char	c;

	str = NULL;
	info = NULL;
	va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			++a;
			a+= ft_type_plus(&format[a], &str);
			if (ft_sequence(str) == -1)
			{
				ft_strdel(&str);
				return (-1);
			}
			info = ft_do(str);
			if (!info)
				return (-1);
			if (str[ft_strlen(str) - 1] == 'c')
			{
				c = (char)va_arg(ap, int);
				//check what c is
				if (info->next->_width == 0)
				{
					temp = ft_strnew(1);
					temp[0] = c;
				}
				else
				{
					temp = (char *) malloc(info->next->_width * sizeof(char));
					if (info->_minus == 1)
						temp[0] = c;
					else
						temp[info->next->_width - 1] = c;
					temp[info->next->_width] = '\0';
				}
				//ft_putstr(temp);
				ft_strcat(&buff[b], temp);
				if (info->next->_width == 0)
					++b;
				else
					b += info->next->_width;
			}
			/*else if (str[ft_strlen(str) - 1] == 's')
			{
				str = va_arg(ap, char*);
				ft_strcpy(&buff[b], str);
				b += ft_strlen(str);
			}
			else if (str[ft_strlen(str) - 1] == 'p')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'd')
			{
			
			}
			else if (str[ft_strlen(str) - 1] == 'i')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'o')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'u')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'x')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'X')
			{
			}
			else if (str[ft_strlen(str) - 1] == 'f')
			{
			}
			else if (str[ft_strlen(str) - 1] == '%')
			{
				buff[b] = '%';
				++b;
			}*/
		}
		else
		{
			buff[b] = format[a];
			++b;
		}
		++a;
	}
	buff[b] = '\0';
	ft_putstr(buff);
	va_end(ap);
	return (b);
}

int	main(void)
{
	int ret;

	ret = va_test("'%8c'  '%-8c'", 't', '8');
	ft_putstr("\n");
	ft_putnbr(ret);
	return (0);
}


