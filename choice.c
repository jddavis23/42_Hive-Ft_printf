/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:28:12 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/21 17:31:25 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				va_arg(*ap, long long unsigned int)));
}

char	*ft_choice_signed(t_flags *info, va_list *ap)
{
	if (info->_h)
		return (ft_solve_signed(info, (short)va_arg(*ap, long long int)));
	else if (info->_ll)
		return (ft_solve_signed(info, va_arg(*ap, long long int)));
	else if (info->_hh)
		return (ft_solve_signed(info, (char)va_arg(*ap, long long int)));
	else if (info->_l)
		return (ft_solve_signed(info, (long)va_arg(*ap, long long int)));
	else
		return (ft_solve_signed(info, (int)va_arg(*ap, long long)));
}
