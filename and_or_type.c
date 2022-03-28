/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:36:26 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/28 13:37:09 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_type(t_flags *info)
{
	if (info->_type != 'X' && info->_type != 'x' && info->_type != 'u' && info->_type != 'o')
		return (1);
	if (info->_type == 'X' || info->_type == 'u' || info->_type == 'x' || info->_type == 'o')
		return (2);
	return (0);
}

int	ft_if_type_i(t_flags *info)
{
	if (info->_type != 'X' || info->_type != 'x' || info->_type != 'o' || info->_type != 'u')
		return (1);
	if (info->_type == 'X' || info->_type == 'x' || info->_type == 'o')
		return (2);
	return (0);
}
