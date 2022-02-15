/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/15 13:18:12 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
//#include <stdarg.h>
#include "ft_printf.h"

char	*ft_type_plus(const char *forma)
{
	int i = 0;
	char *type_plus;

	if (forma[0] == '%')
	{
		type_plus = ft_strdup("%");
		return (type_plus);
	}
	while (forma[i] != 'd' || forma[i] != 'i' || forma[i] != 'o' || 
			forma[i] != 'u' || forma[i] != 'x' || forma[i] != 'X' || 
			forma[i] != 'c' || forma[i] != 's' || forma[i] != 'p' || 
			forma[i] != 'f')
	{
		if (forma[i + 1] == '%' || forma[i + 1] == '%')
			return (NULL);
		++i;
	}
	type_plus = ft_strnew(i);
	ft_strncpy(type_plus, forma, i);
	return (type_plus);
}




int	va_test(const char *format)//, ...)
{
	//va_list ap;
	int a = 0;
	int b = 0;
	//char buff[100];
	char *str;

	//va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			++a;
			str = ft_type_plus(&format[a]);
			ft_putstr(str);
			ft_putchar('\n');
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
		/*else
		{
			buff[b] = format[a];
			++b;
		}*/
		++a;
		ft_putchar('-');
	}
	//buff[b] = '\0';
	//ft_putstr(buff);
	//va_end(ap);
	return (b);
}

int	main(void)
{
	int ret;

	ret = va_test("checking %342234hjjfd jfdkd %gggggo");
	ft_putstr("\n");
	ft_putnbr(ret);
	return (0);
}


