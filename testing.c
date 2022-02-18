/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:16 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/18 17:49:55 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

/*char hex_digit(int v, char c) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
	{
		if (c == 'x')
        	return 'a' + v - 10;
		else if (c == 'X')
        	return 'A' + v - 10;
	}
	return ('0');
}

char	*ft_convert_hex(int nb, char c)
{
	int		count = 0;
	int		sign = 1;
	char	*str;
	int		dup_nb;

	dup_nb = nb;
	str = NULL;
	if (nb < 0)
	{
		sign = -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	str = ft_strnew(count);
	if (sign == -1)
		str[0] = '-';
	while (dup_nb > 0)
	{
		str[--count] = hex_digit(dup_nb % 16, c);
		dup_nb /= 16;
	}
	return (str);
}*/


/*void print_address_hex(void* p0) 
{
    int i;
    uintptr_t p = (uintptr_t)p0;

    ft_putchar('0');
   	ft_putchar('x');
    i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
        ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
    }
}*/




int ft_oct(int nb)
{
	int result = 0;
	int multi = 1;

	while (nb > 0)
	{
		result += (nb % 8) * multi;
		nb /= 8;
		multi *= 10;
	}
	return (result);
}

int main(void)
{
	int i = 0;

	while (i <= 128)
	{
		//ft_putnbr(ft_oct(i));
		//printf("   %o", i++);
	//	ft_putchar('\n');
		i++;
	}
	printf("%o,", 0127);




  // int i = 0;

//	while (i < 130)
	//	printf("%d\n", 0XF);
	/*int	i = 2;
	char c = 'k';
	print_address_hex((void*)&i);
	printf("\n%p\n", &i);
	print_address_hex((void*)&c);
	printf("\n%p", &c);*/
	/*
	//int f = 50;
	//int *nbr = &f;
	//printf("%*d\n", 1, 242424);
	//printf("%2$*1$d\n", 1, 242424);
	printf("\nFLAG = 0\n");
	printf("%10.1s'    %x\n", "jeff", 012);
	printf("%0i   %i\n", -1, -1);
	printf("%04o   %o\n", -1, -1);
	printf("%07u   %u\n", -1, -1);
	printf("%.9x   %x\n", -1, -1);
	printf("%01X   %X\n", -1, -1);


	printf("\nFLAG = -\n");
	printf("%-6d   %d\n", -24, 24);
	printf("%-10i   %i\n", -10, 10);
	printf("%-o   %o\n", -3, 3);
	printf("%-u   %u\n", -97, 97);
	printf("%-x   %x\n", -67, 67);
	printf("%-X   %X\n", 0, 0);


	printf("\nFLAG = space\n");
	printf("% d'   %d\n", -24, 24);
	printf("'% i'   %i\n", 100, 10);
	//printf("% o   % o\n", -3, 3);
	//printf("% u   % u\n", -97, 97);
	//printf("% x   % x\n", -67, 67);
	//printf("% X   % X\n", 0, 0);


	printf("\nFLAG = +\n");
	printf("%+d   %d\n", 24, 24);
	printf("%+i   %i\n", -10, 10);
	//printf("%+o   %o\n", 3, 3);
	//printf("%+u   %u\n", 97, 97);
	//printf("%+x   %x\n", 67, 67);
	//printf("%+X   %X\n", 0, 0);


	printf("\nFLAG = #\n");
	//printf("%#d   %d\n", 24, 24);
	//printf("%#i   %i\n", 10, 10);
	printf("%#o   %o\n", 3, 3);
	//printf("%#u   %u\n", 97, 97);
	printf("%#x   %x\n", 67, 67);
	printf("%#X   %X\n", 0, 0);
	*/


	return (0);
}
