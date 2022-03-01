/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:36:17 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/01 17:19:40 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		_space;
	int		_zero;
	int		_plus;
	int		_hash;
	int		_minus;
	int		_h_or_o;
	char	_h_prfx[3];
	char	_type;
	int			_width;
	int			_precision;
	int			_p_true;
	int	_hh;
	int	_h;
	int	_ll;
	int	_l;
	//t_width	*next;
}				t_flags;

typedef int ft_undef_behav(t_flags *info);

int	ft_c_behaviour(t_flags *info);
int	ft_s_behaviour(t_flags *info);
int	ft_p_behaviour(t_flags *info);

ft_undef_behav *f_array[3] =
{
	ft_c_behaviour,
	ft_s_behaviour,
	ft_p_behaviour,
};

char	*ft_solve_c_s(t_flags *info, char *str);
int		va_test(const char *format, ...); //CHANGE
#endif
