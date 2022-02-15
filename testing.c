/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:16 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/15 12:18:19 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	//printf("%*d\n", 1, 242424);
	//printf("%2$*1$d\n", 1, 242424);
	printf("\nFLAG = 0\n");
	printf("%0d   %d\n", 0xf0, -24);
	printf("%0i   %i\n", -1, -1);
	printf("%04o   %o\n", -1, -1);
	printf("%07u   %u\n", -1, -1);
	printf("%09x   %x\n", -1, -1);
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



	return (0);
}
