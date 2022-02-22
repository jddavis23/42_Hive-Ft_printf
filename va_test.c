/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/22 17:48:39 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

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
	in_precision->_p_true = 0;
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
		info->next->_width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
	}
	if (str[i] == '.')
	{
		info->next->next->_p_true = 1;
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
	/*
	ft_putstr("_type = ");
	ft_putchar(info->_type);
	ft_putchar('\n');
	ft_putstr("_space = ");
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
	ft_strdel(&str);   //isnt working how i thought it would
	return (info);
}

char	*ft_solve_c(t_flags *info, char c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (info->next->_width == 0)
	{
		temp = ft_strnew(1);
		if (!temp)
			return (NULL);
		temp[0] = c;
	}
	else
	{
		temp = ft_strnew(info->next->_width);
		if (!temp)
			return (NULL);
		if (info->_minus)
		{
			temp[i++] = c;
			while (i < info->next->_width)
				temp[i++] = ' ';
		}
		else
		{
			temp[info->next->_width - 1] = c;
			while (temp[i] != c)
				temp[i++] = ' ';
		}
	}
	return (temp);
}

char	*ft_solve_s(t_flags *info, char *str)
{
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	checker = 0;
	temp = NULL;
	if (info->next->next->_precision)
	{
		if (info->next->next->_precision < (int)ft_strlen(str))
		{
			checker = 1;
			temp = ft_strnew(info->next->next->_precision);
			ft_strncpy(temp, str, info->next->next->_precision);
			str = temp;
		}
	}
	if (info->next->_width <= (int)ft_strlen(str))
	{
		temp = ft_strdup(str);
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = ft_strnew(info->next->_width);
		if (!temp)
			return (NULL);
		if (info->_minus)
		{
			ft_strcat(temp, str);
			i = ft_strlen(str);
			while (i < info->next->_width)
				temp[i++] = ' ';
		}
		else
		{
			ft_strcpy(&temp[info->next->_width - (int)ft_strlen(str)], str);
			while (i < (info->next->_width - (int)ft_strlen(str)))
				temp[i++] = ' ';
		}
	}
	if (checker == 1)
		ft_strdel(&str);
	return (temp);
}


int ft_oct(int nb)
{
	int result = 0;
	int multi = 1;
	long lnb = nb;
	int sign = 1;

	if (lnb < 0)
	{
		lnb *= -1;
		sign = -1;
	} // dont think this is needed. Make sure and remove
	while (lnb > 0)
	{
		result += (lnb % 8) * multi;
		lnb /= 8;
		multi *= 10;
	}
	return (result * sign);
}

char hex_digit(int v, char c) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
	{
		if (c == 'x')
        	return 'a' + v - 10;
		else if (c == 'X')
        	return 'A' + v - 10;
	}
	return ('0');
}

char	*ft_convert_hex(int nb, char c)
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
		nb /= 16;
		count++;
	}
	str = ft_strnew(count);
	while (dup_nb > 0)
	{
		str[--count] = hex_digit(dup_nb % 16, c);
		dup_nb /= 16;
	}
	return (str);
}

int	ft_precision_nb(t_flags *info, char **str)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (info->next->next->_precision > (int)ft_strlen(*str))
	{
		temp = ft_strnew(info->next->next->_precision);
		if (!temp)
			return (-1);
		while (i < (info->next->next->_precision - (int)ft_strlen(*str)))
			temp[i++] = '0';
		ft_strcpy(&temp[i], *str);
		ft_strdel(str);
		*str = temp;
		return (1);
	}
	return (0);
}

char	*ft_solve_x(t_flags *info, int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;
	char	c;

	c = info->_type;
	i = 0;
	temp = NULL;
	str = ft_convert_hex(nb, info->_type);
	checker = ft_precision_nb(info, &str);
	if (info->next->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->next->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_minus)
		{
			if (info->_hash && checker == 0)
			{
				temp[i++] = '0';
				temp[i++] = c;
			}
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->next->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->next->next->_p_true)
		{
			if (info->_hash && checker == 0)
			{
				temp[i++] = '0';
				temp[i++] = c;
			}
			while (i < info->next->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			if ((((info->next->_width - (int)ft_strlen(str) - 2)) > 0) && info->_hash)
			{
				ft_strdel(&temp);
				temp = ft_strnew(2 + ft_strlen(str));
			}//double check no overflow is present
			while (i < (info->next->_width - (int)ft_strlen(str) - 2))
				temp[i++] = ' ';
			if ((info->_hash && checker == 0))// || ft_atoi(str) != 0)
			{
				temp[i++] = '0';
				temp[i++] = c;
			}
			else
			{
				temp[i++] = ' ';
				temp[i++] = ' ';
			}
			ft_strcpy(&temp[i], str);
		}
		ft_strdel(&str);
		str = temp;
	}
	else
	{
		if (info->_hash) //change here
		{
			temp = ft_strnew(ft_strlen(str) + 2);
			temp[i++] = '0';
			temp[i++] = c;
			ft_strcpy(&temp[i], str);
			ft_strdel(&str);
			str = temp;
		}
	}
	return (str);
}


char	*ft_solve_o(t_flags *info, int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	temp = NULL;
	str = ft_itoa(ft_oct(nb));
	checker = ft_precision_nb(info, &str);
	if (info->next->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->next->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_minus)
		{
			if (info->_hash && checker == 0)
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->next->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->next->next->_p_true)
		{
			while (i < info->next->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			while (i < (info->next->_width - (int)ft_strlen(str) - 1))
				temp[i++] = ' ';
			if (info->_hash && checker == 0)
				temp[i++] = '0';
			else
				temp[i++] = ' ';
			ft_strcpy(&temp[i], str);
		}
		ft_strdel(&str);
		str = temp;
	}
	else
	{
		if (info->_hash && checker == 0) //change here, may not need to check checker
		{
			temp = ft_strnew(ft_strlen(str) + 1);
			temp[i++] = '0';
			ft_strcpy(&temp[i], str);
			ft_strdel(&str);
			str = temp;
		}
	}
	return (str);
}



int	ft_solve(va_list *ap, t_flags *info)
{
	char	*str;

	str = NULL;
	if (info->_type == 'c')
		str = ft_solve_c(info, (char)va_arg(*ap, int));
	else if (info->_type == 's')
		str = ft_solve_s(info, va_arg(*ap, char*));
	else if (info->_type == 'o')
		str = ft_solve_o(info, va_arg(*ap, int));
	else if (info->_type =='x' || info->_type == 'X')
		str = ft_solve_x(info, va_arg(*ap, int));
	//dont forget to include %%
	if (!str)
		return (-1);
	ft_putstr(str);
	ft_strdel(&str);
	return (1);
}

int	va_test(const char *format, ...)
{
	va_list ap;
	int		a = 0;
	int		b = 0;
	char	*str;
	t_flags	*info;

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
			if (ft_solve(&ap, info) == -1)
				return (-1);
		}
		else
			ft_putchar(format[a]);
		++a;
	}
	va_end(ap);
	return (b);
}

int	main(void)
{
	int ret = 0;
	//int *nbr = NULL;
	//*nbr = 48;

//############%o######################

	printf("TEST %%#5.7o\n");
	va_test("%#5.7o-m\n", 8);
	printf("%#5.7o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#5.o\n");
	ret = va_test("%#5.o-m\n", 8);
	printf("%#5.o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#05.o\n");
	ret = va_test("%#05.o-m\n", 8);
	printf("%#05.o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%05.o\n");
	ret = va_test("%05.o-m\n", 8);
	printf("%05.o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#05o\n");
	ret = va_test("%#05o-m\n", 8);
	printf("%#05o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%-#5o\n");
	ret = va_test("%-#5o-m\n", 8);
	printf("%-#5o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%-5.3o\n");
	ret = va_test("%-5.3o-m\n", 8);
	printf("%-5.3o-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#10o\n");
	ret = va_test("%#10o-m\n", 8);
	printf("%#10o-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%-o\n");
	ret = va_test("%-o-m\n", 8);
	printf("%-o-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%-10o\n");
	ret = va_test("%-10o-m\n", 8);
	printf("%-10o-p\n", 8);
	va_test("\n\n");

//#############%x#################

	printf("TEST %%5.3x\n");
	va_test("%5.3x-m\n", 8);
	printf("%5.3x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#5.7x\n");
	va_test("%#5.7x-m\n", 8);
	printf("%#5.7x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#5.x\n");
	ret = va_test("%#5.x-m\n", 8);
	printf("%#5.x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#05.x\n");
	ret = va_test("%#05.x-m\n", 8);
	printf("%#05.x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%05.x\n");
	ret = va_test("%05.x-m\n", 8);
	printf("%05.x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#05x\n");
	ret = va_test("%#05x-m\n", 8);
	printf("%#05x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%-#5x\n");
	ret = va_test("%-#5x-m\n", 8);
	printf("%-#5x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%-5.3x\n");
	ret = va_test("%-5.3x-m\n", 8);
	printf("%-5.3x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#10x\n");
	ret = va_test("%#10x-m\n", 8);
	printf("%#10x-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%-x\n");
	ret = va_test("%-x-m\n", 8);
	printf("%-x-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%-10x\n");
	ret = va_test("%-10x-m\n", 8);
	printf("%-10x-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#2x\n");
	ret = va_test("%#2x-m THIS ISNT WORKING. CHECK OCTAL TOO\n", 0);
	printf("%#2x-p\n", 0);
	va_test("\n\n");

	//#############%X#################

	printf("TEST %%02X\n");
	ret = va_test("%02X-m\n", 0);
	printf("%02X-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%5.3X\n");
	va_test("%5.3X-m\n", 8);
	printf("%5.3X-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#5.7X\n");
	va_test("%#5.7X-m\n", 56);
	printf("%#5.7X-p\n", 56);
	va_test("\n\n");

	printf("TEST %%#5.X\n");
	ret = va_test("%#5.X-m\n", 90);
	printf("%#5.X-p\n", 90);
	va_test("\n\n");

	printf("TEST %%#05.X\n");
	ret = va_test("%#05.X-m\n", 12);
	printf("%#05.X-p\n", 12);
	va_test("\n\n");

	printf("TEST %%05.X\n");
	ret = va_test("%05.X-m\n", 123);
	printf("%05.X-p\n", 123);
	va_test("\n\n");

	printf("TEST %%#05X\n");
	ret = va_test("%#05X-m\n", 97);
	printf("%#05X-p\n", 97);
	va_test("\n\n");

	printf("TEST %%-#5X\n");
	ret = va_test("%-#5X-m\n", 53);
	printf("%-#5X-p\n", 53);
	va_test("\n\n");

	printf("TEST %%-5.3X\n");
	ret = va_test("%-5.3X-m\n", 77);
	printf("%-5.3X-p\n", 77);
	va_test("\n\n");

	printf("TEST %%#10X\n");
	ret = va_test("%#10X-m\n", 219);
	printf("%#10X-p\n", 219);
	va_test("\n\n");
	
	printf("TEST %%-X\n");
	ret = va_test("%-X-m\n", 0);
	printf("%-X-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%03X\n");
	ret = va_test("%03X-m\n", 0);
	printf("%03X-p\n", 0);
	va_test("\n\n");

	
	printf("TEST %%-10X\n");
	ret = va_test("%-10X-m\n", 1002);
	printf("%-10X-p\n", 1002);
	va_test("\n\n");

	printf("TEST %%#2X\n");
	ret = va_test("%#2X-m\n", 8);
	printf("%#2X-p\n", 8);
	va_test("\n\n");
	return (0);
}


