/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:28:56 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/15 15:27:17 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Creating t_flags srruct to be reused for all type specifiers.
 * 
 * On intial call of function, struct is malloc'd and _ret is set to zero.
 * 
 * _ret is the final returned value, after the string and arguments are printed.
 *
 * After initial call, every other variable is reassigned to zero for reuse. 
 */

t_flags	*ft_create_struct(t_flags *in_flags)
{
	if (!in_flags)
	{
		in_flags = (t_flags *) malloc(sizeof(t_flags));
		if (!in_flags)
			return (NULL);
		in_flags->_ret = 0;
	}
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
	in_flags->_el = 0;
	in_flags->_gt = 0;
	return (in_flags);
}
