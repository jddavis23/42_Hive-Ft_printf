/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/04 12:37:02 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  //REMOVE

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

	in_flags = (t_flags *) malloc(sizeof(t_flags));
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


t_flags	*ft_do(char *str)
{
	t_flags *info;

	info = ft_true_struct(str, str[ft_strlen(str) - 1]);
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

/*char	*ft_solve_c_s(t_flags *info, char *str)
{
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	checker = 0;
	temp = NULL;
	if (info->_type == 's')
	{
		if (info->_precision)
		{
			if (info->_precision < (int)ft_strlen(str))
			{
				checker = 1;
				temp = ft_strnew(info->_precision);
				ft_strncpy(temp, str, info->_precision);
				str = temp;
			}
		}
	}
	if (info->_width <= (int)ft_strlen(str))
	{
		temp = ft_strdup(str);
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = ft_strnew(info->_width);
		if (!temp)
			return (NULL);
		if (info->_minus)
		{
			ft_strcat(temp, str);
			i = ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else
		{
			ft_strcpy(&temp[info->_width - (int)ft_strlen(str)], str);
			while (i < (info->_width - (int)ft_strlen(str)))
				temp[i++] = ' ';
		}
	}
	if (checker == 1 || info->_type == 'c')
		ft_strdel(&str);
	return (temp);
}*/


/*char ft_char_digit(unsigned int v, char c) 
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
}*/

/*char	*ft_x_o_conv(unsigned int nb, char c, int choice)
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

/*int	ft_precision_nb(t_flags *info, char **str)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (info->_precision > (int)ft_strlen(*str))
	{
		temp = ft_strnew(info->_precision);
		if (!temp)
			return (-1);
		while (i < (info->_precision - (int)ft_strlen(*str)))
			temp[i++] = '0';
		ft_strcpy(&temp[i], *str);
		ft_strdel(str);
		*str = temp;
		return (1);
	}
	return (0);
}*/

/*char	*ft_solve_o_x(t_flags *info, unsigned int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;
	int		sub;

	sub = 2;
	if (info->_type == 'o')
		sub = 1;
	i = 0;
	temp = NULL;
	str = ft_x_o_conv(nb, info->_type, info->_div);
	checker = ft_precision_nb(info, &str);
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->_width);
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
		}
		ft_strdel(&str);
		str = temp;
	}
	else
	{
		if (info->_hash && nb != 0) //change here
		{
			temp = ft_strnew(ft_strlen(str) + sub);
			ft_strcpy(&temp[i], info->_h_prfx);
			i += ft_strlen(info->_h_prfx);
			ft_strcpy(&temp[i], str);
			ft_strdel(&str);
			str = temp;
		}
	}
	return (str);
}*/


/*char	*ft_solve_o(t_flags *info, unsigned int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	temp = NULL;
	str = ft_x_o_conv(nb, info->_type, 8); //cant change unsigned int with itoa??
	checker = ft_precision_nb(info, &str);
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_minus)
		{
			if (info->_hash && checker == 0 && nb != 0)
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->_p_true)
		{
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			while (i < (info->_width - (int)ft_strlen(str) - 1))
				temp[i++] = ' ';
			if (info->_hash && checker == 0 && nb != 0)
				temp[i++] = '0';
			else
				temp[i++] = ' ';
			if (nb == 0 && info->_p_true && !info->_precision) //check with the && and zero
				temp[i] = ' ';
			else	
				ft_strcpy(&temp[i], str);
		}
		ft_strdel(&str);
		str = temp;
	}
	else
	{
		if (info->_hash && checker == 0 && nb != 0) //change here, may not need to check checker
		{
			temp = ft_strnew(ft_strlen(str) + 1);
			temp[i++] = '0';
			ft_strcpy(&temp[i], str);
			ft_strdel(&str);
			str = temp;
		}
	}
	return (str);
}*/

/*char	*ft_solve_d_i_u(t_flags *info, int nb)
{
	char	*str;
	char	*temp;
	int		i;
	int		checker;

	i = 0;
	temp = NULL;
	str = ft_itoa(nb);
	checker = ft_precision_nb(info, &str);
	if (info->_width > (int)ft_strlen(str))
	{
		temp = ft_strnew(info->_width);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		else if (info->_space && nb >= 0)
			temp[i++] = ' ';
		if (info->_minus)
		{
			ft_strcpy(&temp[i], str);
			i += ft_strlen(str);
			while (i < info->_width)
				temp[i++] = ' ';
		}
		else if (info->_zero && !info->_p_true)
		{
			while (i < info->_width - (int)ft_strlen(str))
				temp[i++] = '0';
			ft_strcpy(&temp[i], str);
		}
		else
		{
			while (i < (info->_width - (int)ft_strlen(str)))
				temp[i++] = ' ';
			if (nb == 0 && !info->_precision && info->_p_true)
				temp[i] = ' ';
			else	
				ft_strcpy(&temp[i], str);
		}
		ft_strdel(&str);
		str = temp;
	}
	else if (info->_plus || info->_space)
	{
		temp = ft_strnew(ft_strlen(str) + 1);
		if (!temp)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (info->_plus && nb >= 0)
			temp[i++] = '+';
		else if (info->_space && nb >= 0)
			temp[i++] = ' ';
		ft_strcpy(&temp[i], str);
		ft_strdel(&str);
		str = temp;
	}
	return (str);
}*/

char	*ft_solve_p(t_flags *info, uintptr_t addi)
{
	char	*str;
	char	*temp;

	temp = NULL;
	str = ft_num_toa(addi, 'x', info->_div);
	temp = ft_strnew(2 + ft_strlen(str));
	ft_strcat(ft_strcpy(temp, info->_h_prfx), str);
	ft_strdel(&str);
	str = temp;
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
			a+= ft_type_plus(&format[a], &str);  //info struct can be created here
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

/*int	main(void)
{
	int ret = 0;

	printf("############%%c######################\n");

	printf("TEST %%-12c\n");
	va_test("%-12c-m\n", 'c');
	printf("%-12c-p\n", 'c');
	va_test("\n\n");

	printf("TEST %%5.c\n");
	ret = va_test("%5.c-m\n", 'c');
	printf("%5.c-p\n", 'c');
	va_test("\n\n");

	printf("TEST %%-5c\n");  
	ret = va_test("%-5c-m\n", 'c');
	printf("%-5c-p\n", 'c');
	va_test("\n\n");
	
	printf("TEST %%c\n");
	ret = va_test("%c-m\n", 'c');
	printf("%c-p\n", 'c');
	va_test("\n\n");

	printf("TEST %%1c\n");
	ret = va_test("%1c-m\n", 'c');
	printf("%1c-p\n", 'c');
	va_test("\n\n");

	printf("TEST %%-1c\n");
	ret = va_test("%-1c-m\n", 'c');
	printf("%-1c-p\n", 'c');
	va_test("\n\n");

	printf("TEST %%-c\n");
	ret = va_test("%-c-m\n", 'c');
	printf("%-c-p\n", 'c');
	va_test("\n\n");

	printf("############%%s######################\n");

	printf("TEST %%s\n");
	va_test("%s-m\n", "this is a string");
	printf("%s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%.16s\n");
	ret = va_test("%.16s-m\n", "this is a string");
	printf("%.16s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%.18s\n");
	ret = va_test("%.18s-m\n", "this is a string");
	printf("%.18s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%5.5s\n");
	ret = va_test("%5.5s-m\n", "this is a string");
	printf("%5.5s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%10.5s\n");
	ret = va_test("%10.5s-m\n", "this is a string");
	printf("%10.5s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%-20s\n");
	ret = va_test("%-20s-m\n", "this is a string");
	printf("%-20s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%-20.5s\n");
	ret = va_test("%-20.5s-m\n", "this is a string");
	printf("%-20.5s-p\n", "this is a string");
	va_test("\n\n");

	printf("TEST %%-1.1s\n");
	ret = va_test("%-1.1s-m\n", "this is a string");
	printf("%-1.1s-p\n", "this is a string");
	va_test("\n\n");
	
	printf("TEST %%-s\n");
	ret = va_test("%-s-m\n", "this is a string");
	printf("%-s-p\n", "this is a string");
	va_test("\n\n");
	
	printf("TEST %%-20.20s\n");
	ret = va_test("%-20.20s-m\n", "this is a string");
	printf("%-20.20s-p\n", "this is a string");
	va_test("\n\n");

printf("############%%o######################\n");

	printf("TEST %%0#10o\n");
	va_test("%0#10o-m\n", 0);
	printf("%0#10o-p\n", 0);
	va_test("\n\n");

	printf("TEST %%#5.o\n");
	ret = va_test("%#5.o-m\n", 32);
	printf("%#5.o-p\n", 32);
	va_test("\n\n");

	printf("TEST %%#05.o\n");
	ret = va_test("%#05.o-m\n", 3);
	printf("%#05.o-p\n", 3);
	va_test("\n\n");

	printf("TEST %%05.o\n");
	ret = va_test("%05.o-m\n", 189);
	printf("%05.o-p\n", 189);
	va_test("\n\n");

	printf("TEST %%#05o\n");
	ret = va_test("%#05o-m\n", 2);
	printf("%#05o-p\n", 2);
	va_test("\n\n");

	printf("TEST %%-#5o\n");
	ret = va_test("%-#5o-m\n", 0);
	printf("%-#5o-p\n", 0);
	va_test("\n\n");

	printf("TEST %%-5.3o\n");
	ret = va_test("%-5.3o-m\n", 0);
	printf("%-5.3o-p\n", 0);
	va_test("\n\n");

	printf("TEST %%#10o\n");
	ret = va_test("%#10o-m\n", 0);
	printf("%#10o-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%-o\n");
	ret = va_test("%-o-m\n", 0);
	printf("%-o-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%-10o\n");
	ret = va_test("%-10o-m\n", 0);
	printf("%-10o-p\n", 0);
	va_test("\n\n");

printf("############%%x######################\n");

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

	printf("TEST %%#x\n");
	ret = va_test("%#x-m\n", 0);
	printf("%#x-p\n", 0);
	va_test("\n\n");

printf("############%%X######################\n");

	printf("TEST %%-#5.3X\n");
	ret = va_test("%-#5.3X-m\n", 3);
	printf("%-#5.3X-p\n", 3);
	va_test("\n\n");
	
	printf("TEST %%5.3X\n");
	va_test("%5.3X-m\n", 8);
	printf("%5.3X-p\n", 8);
	va_test("\n\n");

	printf("TEST %%#10.7X\n");
	va_test("%#10.7X-m\n", 56);
	printf("%#10.7X-p\n", 56);
	va_test("\n\n");

	printf("TEST %%#5.X\n");
	ret = va_test("%#5.X-m\n", 0); 
	printf("%#5.X-p\n", 0);
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
	
	
printf("############%%d/i######################\n");

	printf("TEST %%02d\n");
	ret = va_test("%02d-m\n", 0);
	printf("%02d-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%5.3d\n");
	va_test("%5.3d-m\n", 0);
	printf("%5.3d-p\n", 0);
	va_test("\n\n");

	printf("TEST %%5.1d\n");
	va_test("%5.1d-m\n", 0);
	printf("%5.1d-p\n", 0);
	va_test("\n\n");

	printf("TEST %%5.d\n");
	ret = va_test("%5.d-m\n", 0);
	printf("%5.d-p\n", 0);
	va_test("\n\n");

	printf("TEST %%05d\n"); //precision dictates if 0 is present or not. CHANGE!!
	ret = va_test("%05d-m\n", 0);
	printf("%05d-p\n", 0);
	va_test("\n\n");

	printf("TEST %%05.d\n");
	ret = va_test("%05.d-m\n", 0);
	printf("%05.d-p\n", 0);
	va_test("\n\n");

	printf("TEST %%05i\n");
	ret = va_test("%05i-m\n", 0);
	printf("%05i-p\n", 0);
	va_test("\n\n");

	printf("TEST %%-5i\n");
	ret = va_test("%-5i-m\n", 0);
	printf("%-5i-p\n", 0);
	va_test("\n\n");

	printf("TEST %%-5.3i\n");
	ret = va_test("%-5.3i-m\n", 0);
	printf("%-5.3i-p\n", 0);
	va_test("\n\n");

	printf("TEST %%10i\n");
	ret = va_test("%10i-m\n", 0);
	printf("%10i-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%-i\n");
	ret = va_test("%-i-m\n", 0);
	printf("%-i-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%03i\n");
	ret = va_test("%03i-m\n", 0);
	printf("%03i-p\n", 0);
	va_test("\n\n");

	
	printf("TEST %%-10i\n");
	ret = va_test("%-10i-m\n", 1002);
	printf("%-10i-p\n", 1002);
	va_test("\n\n");

	printf("TEST %%+i\n");
	ret = va_test("%+i-m\n", 8);
	printf("%+i-p\n", 8);
	va_test("\n\n");
	
	
	printf("TEST %% i\n");
	ret = va_test("% i-m\n", 8);
	printf("% i-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %% 2i\n");
	ret = va_test("% 2i-m\n", 8);
	printf("% 2i-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%+2i\n");
	ret = va_test("%+2i-m\n", 8);
	printf("%+2i-p\n", 8);
	va_test("\n\n");
	
	printf("TEST %%+i\n");
	ret = va_test("%+i-m\n", 0);
	printf("%+i-p\n", 0);
	va_test("\n\n");
	
	
	printf("TEST %% i\n");
	ret = va_test("% i-m\n", 0);
	printf("% i-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%05i\n");
	ret = va_test("%05i-m\n", 0);
	printf("%05i-p\n", 0);
	va_test("\n\n");
	
	printf("TEST %%+2i\n");
	ret = va_test("%+2i-m\n", 0);
	printf("%+2i-p\n", 0);
	va_test("\n\n");
	return (0);
}

*/
