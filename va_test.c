/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/16 11:59:05 by jdavis           ###   ########.fr       */
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
	t_flags		in_flags;
	t_width		in_width;
	t_precision	in_precision;
	t_length	in_length;

	in_flags = (t_flags *) malloc(sizeof(t_flags));
	in_flags._space = 0;
	in_flags._zero = 0;
	in_flags._minus = 0;
	in_flags._plus = 0;
	in_flags._hash = 0;
	in_width = (t_width *) malloc(sizeof(t_width));
	in_width._width = 0;
	in_precision = (t_precision *) malloc(sizeof(t_precision));
	in_precision._precision._precision = 0;
	in_length = (t_length *) malloc(sizeof(t_length));
	in_length._hh = 0;
	in_length._h = 0;
	in_length._ll = 0;
	in_length._l = 0;
	in_flags->next = in_width;
	in_width->next = in_precision;
	in_precision->next = in_length;
	in_length->next = NULL;
	return (in_flags);
}


void	ft_true_struct(char *str)
{
	int	i = 0;
	int	j = 0;
	t_flags info;

	if (
}




int	va_test(const char *format)//, ...)
{
	//va_list ap;
	int a = 0;
	int b = 0;
	//char buff[100];
	char *str;

	str = NULL;
	//va_start(ap, format);
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
			/*if (format[a] == 'c')
			{
				buff[b] = (char)va_arg(ap, int);
				++b;
			}
			else if (format[a] == 's')
			{
				str = va_arg(ap, char*);
				ft_strcpy(&buff[b], str);
				b += ft_strlen(str);
			}
			else if (format[a] == '%')
			{
				buff[b] = '%';
				++b;
			}*/
		}
		//else
		//{
			//buff[b] = format[a];
			//++b;
		//}
		++a;
	}
	//buff[b] = '\0';
	//ft_putstr(buff);
	//va_end(ap);
	return (b);
}

int	main(void)
{
	int ret;

	ret = va_test("checking %d jfdkd %o");
	ft_putstr("\n");
	ft_putnbr(ret);
	return (0);
}


