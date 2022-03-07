/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:28:27 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/07 11:28:49 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
