/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:28:27 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/05 12:04:41 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_solve_p(t_flags *info, uintptr_t addi)
{
	char	*str;
	char	*temp;

	temp = NULL;
	str = ft_llu_toa(addi, &info);
	if (info->_p_true && addi == 0)
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	temp = ft_strcat(ft_strcpy(ft_strnew(2 + ft_strlen(str)), info->_h_prfx),
			str);
	ft_strdel(&str);
	str = temp;
	return (str);
}
