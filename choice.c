/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:28:12 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/24 19:04:18 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //REMOVE

char	*ft_choice_unsigned(t_flags *info, va_list *ap)
{
	if (info->_h)
		return (ft_solve_unsigned(info,
				(unsigned short)va_arg(*ap, long long unsigned int)));
	else if (info->_hh)
		return (ft_solve_unsigned(info,
				(unsigned char)va_arg(*ap, long long unsigned int)));
	else if (info->_l)
		return (ft_solve_unsigned(info,
				(unsigned long)va_arg(*ap, long long unsigned int)));
	else if (info->_ll)
		return (ft_solve_unsigned(info,
				va_arg(*ap, long long unsigned int)));
	else
		return (ft_solve_unsigned(info,
				(unsigned)va_arg(*ap, long long unsigned int)));
}

char	*ft_choice_signed(t_flags *info, va_list *ap)
{
	char	*str;

	str = NULL;
	if (info->_type != '%' && info->_type != 'f')
	{
		if (info->_h)
			str = ft_num_toa((short int)va_arg(*ap, long long int), info, 10);
		else if (info->_ll)
			str = ft_num_toa(va_arg(*ap, long long int), info, 10);
		else if (info->_hh)
			str = ft_num_toa((char)va_arg(*ap, long long int), info, 10);
		else if (info->_l)
			str = ft_num_toa((long)va_arg(*ap, long long int), info, 10);
		else
			str = ft_num_toa((int)va_arg(*ap, long long int), info, 10);
	}
	else if (info->_type == 'f')
	{
		if (info->_el)
			str = ft_ftoa(info, (long double)va_arg(*ap, long double));
		else if (info->_l)
			str = ft_ftoa(info, va_arg(*ap, double));
		else
			str = ft_ftoa(info, va_arg(*ap, double));
		//return (ft_solve_f(info, str, info->_gt));
	}
	else
		str = ft_num_toa(0, info, 0);
	if (str)
		return (ft_solve_signed(info, str, info->_gt));//(short int)va_arg(*ap, long long int)));
	else
		return (NULL);
}

/*char	*ft_choice_f(t_flags *info, va_list *ap)
{
	if (info->_el)
		return (ft_solve_f(info, (long double)va_arg(*ap, long double)));
	else if (info->_l)
		return (ft_solve_f(info, va_arg(*ap, double)));
	else
		return (ft_solve_f(info, va_arg(*ap, double)));
}*/
