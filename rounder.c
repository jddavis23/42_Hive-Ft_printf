/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:41:52 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/24 13:18:28 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_carry(int i, char **str, int carry)
{
	while (--i >= 0 && carry)
	{
		if (carry && (*str)[i] != '.')
		{
			if ((*str)[i] < '9')
			{
				carry = 0;
				(*str)[i] += 1;
			}
			else
			{
				(*str)[i] = '0';
				carry = 1;
			}
		}
	}
}

void	ft_rounder(char **str, t_flags *info)
{
	int	i;
	int	carry;

	carry = 0;
	i = ft_strlen_stop(*str, '.') + info->_precision;
	if ((*str)[i + 1] >= '5')
	{
		if ((*str)[i] < '9')
			(*str)[i] += 1;
		else
		{
			(*str)[i] = '0';
			carry = 1;
		}
	}
	(*str)[i + 1] = '\0';
	ft_carry(i, str, carry);
}
