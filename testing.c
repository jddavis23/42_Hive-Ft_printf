/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:16 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/18 13:45:08 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

char hex_digit(int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

void print_address_hex(void* p0) 
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
}




/*int ft_oct(int nb)
{
	int result = 0;
	int multi = 1;

	if (nb > 7)
	{
		while (nb > 0)
		{
			result += (nb % 8) * multi;
			nb /= 8;
			multi *= 10;
		}
	}
	else
		result = nb;
	return (result);
}*/

int main(void)
{
  // int i = 0;

//	while (i < 130)
	//	printf("%d\n", 0XF);
	int	i = 2;
	char c = 'k';
	print_address_hex((void*)&i);
	printf("\n%p\n", &i);
	print_address_hex((void*)&c);
	printf("\n%p", &c);
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
