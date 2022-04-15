/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:38:07 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/15 14:50:11 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Converting intergers to ascii; base 10 and hexidecimal conversions 
 */

char	ft_char_digit(unsigned int v, char c)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
	{
		if (c == 'x' || c == 'p')
			return ('a' + v - 10);
		else if (c == 'X')
			return ('A' + v - 10);
	}
	return ('0');
}
