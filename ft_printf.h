/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:36:17 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/11 14:37:12 by jdavis           ###   ########.fr       */
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
	int		_h_sub;
	char	_h_prfx[3];
	int		_minus;
	int		_div;
	char	_type;
	int		_width;
	int		_precision;
	int		_p_true;
	int		_p_check;
	int		_hh;
	int		_h;
	int		_ll;
	int		_l;
	int		_ret;
}				t_flags;

//typedef int ft_undef_behav(t_flags *info);

//int	ft_c_behaviour(t_flags *info);
//int	ft_s_behaviour(t_flags *info);
//int	ft_p_behaviour(t_flags *info);

/*ft_undef_behav *f_array[3] =
{
	ft_c_behaviour,
	ft_s_behaviour,
	ft_p_behaviour,
};*/

char	*ft_solve_c_s(t_flags *info, char *str);
int		ft_printf(const char *format, ...);
int		ft_precision_nb(t_flags *info, char **str);
char	ft_char_digit(unsigned int v, char c);
char	*ft_num_toa(long long int nb, char c, int choice);
char	*ft_solve_o_x(t_flags *info, unsigned int nb);
void	ft_apply_hash(t_flags *info, unsigned int nb, char **temp, int *i);
char	*ft_solve_d_i(t_flags *info, int nb);
char	*ft_solve_u(t_flags *info, long long int nb);
char	*ft_solve_p(t_flags *info, uintptr_t addi);

#endif
