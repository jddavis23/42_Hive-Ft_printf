/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:32:39 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/09 13:14:20 by jdavis           ###   ########.fr       */
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

/*char	*ft_solve_p(t_flags *info, uintptr_t addi)
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
}*/

long double	ft_power(double nb, int power)
{
	long double result;
	long double help = 0;

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
		return (result);
	}
	if (power < 0)
	{
		while (power <= -1)
		{
			help += 1 / ft_power(nb, (power * -1));
			++power;
		}
	}
	return (help);
}


void	ft_floating(t_flags *info, long double nb)
{
	/*
	long long int result = 0;
	long double help = 0;
	int i = 0;
	//int sign = 1;
	char	hold[141];
	char	*str;
	long int int_nb;

	str = NULL;
	ft_bzero(hold, 141);
	int_nb = (long long int)nb;
	if (info)
		printf("%f----\n", (double)nb);
	while (i < 50)
	{
		hold[i++] = (int_nb % 2) + '0';
		int_nb /= 2;
	}
	//hold[i] = '\0';
	i = 0;
	while (i < 50)
	{
		result += (hold[i] - '0') * ft_power(2, i);
		++i;
	}
	i = 0;
	str = ft_num_toa(result, info->_type, 10);
	nb -= (long long int)nb;
	ft_bzero(hold, 51);
	while (i < 50)
	{
		hold[i++] = (int)(nb * 2) + '0';
		nb /= 2;
	}//add decimal calculation
	i = 0;
	while (i < 15)
	{
		printf("%.10Lf--\n", help);
		help += (hold[i] - '0') * ft_power(2, (i * -1));
		if (help +  (hold[i] - '0') * ft_power(2, (i * -1)) > 0.147)
			break;
		++i;
	}	
	printf("\n%Lf---\n", help);
	//ft_putnbr(result);

	
	
*/	
	
	
	
	
	
	///////////////////////////////////////
	int	i;
	long long dup_nb;
	char		*str;
	int			sign;
	int			count;
	char		*temp;

	sign = 1;
	str = NULL;
	dup_nb = nb;
	printf("%Lf***\n", nb);
	temp = ft_num_toa((long long int)nb, info->_type, 10);
	count = 0;
	if (nb < 0)
	{
		sign *= -1;
		nb *= -1;
		++count;
	}
	while (nb >= 1)
	{
		nb /= 10;
		++count;
	}
	nb = nb * 100; //raise to the power of count or count - 1 if sign == -1
	nb = (long double)(nb - (int)nb);
	if (nb > 0)
	{
		++count;
		nb *= 10000000;  //should be dependent on precision
		dup_nb = (long long)nb;
		while (nb >= 1)
		{
			nb /= 10;
			++count;
		}
	}
	else
		count += 7;
	str = ft_strnew(count);
	ft_strcat(str, temp);
	ft_strdel(&temp);
	i = ft_strlen(str);
	str[i] = '.';;
	//printf("count = %d    i = %d\n", count, i);
	while (--count > i)
	{
		str[count] = ft_char_digit((dup_nb % 10), info->_type);
	   dup_nb /= 10;
	}
	ft_putstr(str);
	//build on
	//return (str);
}





char	*ft_solve_f(t_flags *info, long double nb)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	str = NULL;

	ft_floating(info, nb);
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
		str = ft_solve_f(info, (long double)va_arg(*ap, double)); // FINISH
	//dont forget to include %%
	if (!str)
		return (-1);
	ft_putstr(str);
	ft_strdel(&str);
	return (1);
}

int	ft_printf(const char *format, ...)
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

