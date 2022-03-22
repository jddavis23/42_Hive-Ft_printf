/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:28:12 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/22 14:15:50 by jdavis           ###   ########.fr       */
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
	if (info->_h)
		return (ft_solve_signed(info, (short int)va_arg(*ap, long long int)));
	else if (info->_ll)
		return (ft_solve_signed(info, va_arg(*ap, long long int)));
	else if (info->_hh)
		return (ft_solve_signed(info, (char)va_arg(*ap, long long int)));
	else if (info->_l)
		return (ft_solve_signed(info, (long)va_arg(*ap, long long int)));
	else
		return (ft_solve_signed(info, (int)va_arg(*ap, long long)));
}

char	*ft_choice_f(t_flags *info, va_list *ap)
{
	if (info->_L)
		return (ft_solve_f(info, (long double)va_arg(*ap, long double)));
	else if (info->_l)
		return (ft_solve_f(info, va_arg(*ap, double)));
	else
		return (ft_solve_f(info, va_arg(*ap, double)));
}
