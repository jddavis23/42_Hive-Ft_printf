/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/14 17:21:21 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int	va_test(const char *format, ...)
{
	va_list ap;
	int a = 0;
	int b = 0;
	char buff[100];
	char *str;

	va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			++a;
			if (format[a] == 'c')
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
			}
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

	ret = va_test("checking");
	ft_putstr("\n");
	ft_putnbr(ret);
	return (0);
}


