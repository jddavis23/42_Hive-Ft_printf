/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:11:32 by jdavis            #+#    #+#             */
/*   Updated: 2022/10/24 11:17:57 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("############ %%c ######################\n");

	printf("TEST %%(0)*c\n");
	ret1 = ft_printf("%*c-m\n", 0, 0);
	ret2 = printf("%*c-p\n", 0, 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%3c\n");
	ret1 = ft_printf("%3c-m\n", 0);
	ret2 = printf("%3c-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%c\n");
	ret1 = ft_printf("%c-m\n", 0);
	ret2 = printf("%c-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-12c\n");
	ret1 = ft_printf("%-12c-m\n", 'c');
	ret2 = printf("%-12c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.c\n");
	ret1 = ft_printf("%5.c-m\n", 'c');
	ret2 = printf("%5.c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5c\n");  
	ret1 = ft_printf("%-5c-m\n", 'c');
	ret2 = printf("%-5c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%c\n");
	ret1 = ft_printf("%c-m\n", 'c');
	ret2 = printf("%c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%1c\n");
	ret1 = ft_printf("%1c-m\n", 'c');
	ret2 = printf("%1c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-1c\n");
	ret1 = ft_printf("%-1c-m\n", 'c');
	ret2 = printf("%-1c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-c\n");
	ret1 = ft_printf("%-c-m\n", 'c');
	ret2 = printf("%-c-p\n", 'c');
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("############ %%s ######################\n");
	
	printf("TEST %%.*s\n");
	ret1 = ft_printf("%.*s-m\n", -5, "42");
	ret2 = printf("%.*s-p\n", -5, "42");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%4.s\n");
	ret1 = ft_printf("%4.s-m\n", "42");
	ret2 = printf("%4.s-p\n", "42");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%3.5s\n");
	ret1 = ft_printf("%3.5s-m\n", NULL);
	ret2 = printf("%3.5s-p\n", NULL);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%s\n");
	ret1 = ft_printf("%s-m\n", "this is a string");
	ret2 = printf("%s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.16s\n");
	ret1 = ft_printf("%.16s-m\n", "this is a string");
	ret2 = printf("%.16s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.18s\n");
	ret1 = ft_printf("%.18s-m\n", "this is a string");
	ret2 = printf("%.18s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.5s\n");
	ret1 = ft_printf("%5.5s-m\n", "this is a string");
	ret2 = printf("%5.5s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%10.5s\n");
	ret1 = ft_printf("%10.5s-m\n", "this is a string");
	ret2 = printf("%10.5s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-20s\n");
	ret1 = ft_printf("%-20s-m\n", "this is a string");
	ret2 = printf("%-20s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-20.5s\n");
	ret1 = ft_printf("%-20.5s-m\n", "this is a string");
	ret2 = printf("%-20.5s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-1.1s\n");
	ret1 = ft_printf("%-1.1s-m\n", "this is a string");
	ret2 = printf("%-1.1s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-s\n");
	ret1 = ft_printf("%-s-m\n", "this is a string");
	ret2 = printf("%-s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-20.20s\n");
	ret1 = ft_printf("%-20.20s-m\n", "this is a string");
	ret2 = printf("%-20.20s-p\n", "this is a string");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("############ %%o ######################\n");
	
	printf("TEST %%#8.3o\n");
	ret1 = ft_printf("%#8.3o-m\n", 0);
	ret2 = printf("%#8.3o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#8.o\n");
	ret1 = ft_printf("%#8.o-m\n", 0);
	ret2 = printf("%#8.o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#08.5o\n");
	ret1 = ft_printf("%#08.5o-m\n", 444);
	ret2 = printf("%#08.5o-p\n", 444);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#-1.o\n");
	ret1 = ft_printf("%#-1.o-m\n", 0);
	ret2 = printf("%#-1.o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%lo\n");
	ret1 = ft_printf("%lo-m\n", LONG_MAX);
	ret2 = printf("%lo-p\n", LONG_MAX);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#.3o\n");
	ret1 = ft_printf("%#.3o-m\n", 1);
	ret2 = printf("%#.3o-p\n", 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#o\n");
	ret1 = ft_printf("%#o-m\n", 0);
	ret2 = printf("%#o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.o  %%.0o\n");
	ret1 = ft_printf("%.o  %.0o-m\n", 0, 0);
	ret2 = printf("%.o  %.0o-p\n", 0, 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#.o  %%#.0o\n");
	ret1 = ft_printf("%#.o  %#.0o-m\n", 0, 0);
	ret2 = printf("%#.o  %#.0o-p\n", 0, 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);


	printf("TEST %%0#10o\n");
	ret1 = ft_printf("%0#10o-m\n", 0);
	ret2 = printf("%0#10o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#5.o\n");
	ret1 = ft_printf("%#5.o-m\n", 32);
	ret2 = printf("%#5.o-p\n", 32);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05.o\n");
	ret1 = ft_printf("%#05.o-m\n", 3);
	ret2 = printf("%#05.o-p\n", 3);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05.o\n");
	ret1 = ft_printf("%05.o-m\n", 189);
	ret2 = printf("%05.o-p\n", 189);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05o\n");
	ret1 = ft_printf("%#05o-m\n", 2);
	ret2 = printf("%#05o-p\n", 2);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-#5o\n");
	ret1 = ft_printf("%-#5o-m\n", 0);
	ret2 = printf("%-#5o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5.3o\n");
	ret1 = ft_printf("%-5.3o-m\n", 0);
	ret2 = printf("%-5.3o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#10o\n");
	ret1 = ft_printf("%#10o-m\n", 0);
	ret2 = printf("%#10o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-o\n");
	ret1 = ft_printf("%-o-m\n", 0);
	ret2 = printf("%-o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-10o\n");
	ret1 = ft_printf("%-10o-m\n", 0);
	ret2 = printf("%-10o-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#1o\n");
	ret1 = ft_printf("%#1o-m\n", 3);
	ret2 = printf("%#1o-p\n", 3);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("############ %%x ######################\n");

	printf("TEST %%#8.3x\n");
	ret1 = ft_printf("%#8.3x-m\n", 0);
	ret2 = printf("%#8.3x-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#8.x\n");
	ret1 = ft_printf("%#8.x-m\n", 0);
	ret2 = printf("%#8.x-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.1x\n");
	ret1 = ft_printf("%5.1x-m\n", 0);
	ret2 = printf("%5.1x-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.x\n");
	ret1 = ft_printf("%5.x-m\n", 0);
	ret2 = printf("%5.x-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#.x  %%#.0x\n");
	ret1 = ft_printf("%#.x  %#.0x-m\n", 0, 0);
	ret2 = printf("%#.x  %#.0x-p\n", 0, 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.x  %%.0x\n");
	ret1 = ft_printf("%.x  %.0x-m\n", 0, 0);
	ret2 = printf("%.x  %.0x-p\n", 0, 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#1x\n");
	ret1 = ft_printf("%#1x-m\n", 3);
	ret2 = printf("%#1x-p\n", 3);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.3x\n");
	ret1 = ft_printf("%5.3x-m\n", 8);
	ret2 = printf("%5.3x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#5.7x\n");
	ret1 = ft_printf("%#5.7x-m\n", 8);
	ret2 = printf("%#5.7x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#5.x\n");
	ret1 = ft_printf("%#5.x-m\n", 8);
	ret2 = printf("%#5.x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05.x\n");
	ret1 = ft_printf("%#05.x-m\n", 8);
	ret2 = printf("%#05.x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05.x\n");
	ret1 = ft_printf("%05.x-m\n", 8);
	ret2 = printf("%05.x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05x\n");
	ret1 = ft_printf("%#05x-m\n", 8);
	ret2 = printf("%#05x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-#5x\n");
	ret1 = ft_printf("%-#5x-m\n", 8);
	ret2 = printf("%-#5x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5.3x\n");
	ret1 = ft_printf("%-5.3x-m\n", 8);
	ret2 = printf("%-5.3x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#10x\n");
	ret1 = ft_printf("%#10x-m\n", 8);
	ret2 = printf("%#10x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-x\n");
	ret1 = ft_printf("%-x-m\n", 8);
	ret2 = printf("%-x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-10x\n");
	ret1 = ft_printf("%-10x-m\n", 8);
	ret2 = printf("%-10x-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#x\n");
	ret1 = ft_printf("%#x-m\n", 0);
	ret2 = printf("%#x-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%x\n");
	ret1 = ft_printf("%x-m\n", -42);
	ret2 = printf("%x-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("############ %%X ######################\n");

	/*uintmax_t jk = 4294967296;
	printf("TEST %%X\n");
	ret1 = ft_printf("%X-m\n", jk);
	ret2 = printf("%jX-p\n", jk);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);*/
	
	printf("TEST %%#5.5hhX\n");
	ret1 = ft_printf("%#5.5hhX-m\n", (unsigned char)0);
	ret2 = printf("%#5.5hhX-p\n", (unsigned char)0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%X\n");
	ret1 = ft_printf("%X-m\n", -42);
	ret2 = printf("%X-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-#5.3X\n");
	ret1 = ft_printf("%-#5.3X-m\n", 3);
	ret2 = printf("%-#5.3X-p\n", 3);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.3X\n");
	ret1 = ft_printf("%5.3X-m\n", 8);
	ret2 = printf("%5.3X-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#10.7X\n");
	ret1 = ft_printf("%#10.7X-m\n", 56);
	ret2 = printf("%#10.7X-p\n", 56);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#5.X\n");
	ret1 = ft_printf("%#5.X-m\n", 0); 
	ret2 = printf("%#5.X-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05.X\n");
	ret1 = ft_printf("%#05.X-m\n", 12);
	ret2 = printf("%#05.X-p\n", 12);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05.X\n");
	ret1 = ft_printf("%05.X-m\n", 123);
	ret2 = printf("%05.X-p\n", 123);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#05X\n");
	ret1 = ft_printf("%#05X-m\n", 97);
	ret2 = printf("%#05X-p\n", 97);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-#5X\n");
	ret1 = ft_printf("%-#5X-m\n", 53);
	ret2 = printf("%-#5X-p\n", 53);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5.3X\n");
	ret1 = ft_printf("%-5.3X-m\n", 77);
	ret2 = printf("%-5.3X-p\n", 77);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#10X\n");
	ret1 = ft_printf("%#10X-m\n", 219);
	ret2 = printf("%#10X-p\n", 219);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-X\n");
	ret1 = ft_printf("%-X-m\n", 0);
	ret2 = printf("%-X-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03X\n");
	ret1 = ft_printf("%03X-m\n", 0);
	ret2 = printf("%03X-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	
	printf("TEST %%-10X\n");
	ret1 = ft_printf("%-10X-m\n", 1002);
	ret2 = printf("%-10X-p\n", 1002);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%#2X\n");
	ret1 = ft_printf("%#2X-m\n", 8);
	ret2 = printf("%#2X-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	
printf("############ %%d/i ######################\n");

	printf("TEST %%+8.3d\n");
	ret1 = ft_printf("%+8.3d-m\n", 0);
	ret2 = printf("%+8.3d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+8.d\n");
	ret1 = ft_printf("%+8.d-m\n", 0);
	ret2 = printf("%+8.d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%08.3d\n");
	ret1 = ft_printf("%08.3d-m\n", 8375);
	ret2 = printf("%08.3d-p\n", 8375);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05.(-15)*d\n");
	ret1 = ft_printf("%05.*d-m\n", -15, 42);
	ret2 = printf("%05.*d-p\n", -15, 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#-10.5d\n");
	ret1 = ft_printf("%-10.5d-m\n", 104);
	ret2 = printf("%-10.5d-p\n", 104);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%hd\n");
	ret1 = ft_printf("%hd-m\n", SHRT_MIN);
	ret2 = printf("%d-p\n", SHRT_MIN);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 03d\n");
	ret1 = ft_printf("% 03d-m\n", 42);
	ret2 = printf("% 03d-p\n", 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 04d\n");
	ret1 = ft_printf("% 04d-m\n", -42);
	ret2 = printf("% 04d-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03d\n");
	ret1 = ft_printf("%03d-m\n", 42);
	ret2 = printf("%03d-p\n", 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 04d\n");
	ret1 = ft_printf("% 04d-m\n", 42);
	ret2 = printf("% 04d-p\n", 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 03d\n");
	ret1 = ft_printf("% 03d-m\n", 0);
	ret2 = printf("% 03d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% d\n");
	ret1 = ft_printf("% d-m\n", -42);
	ret2 = printf("% d-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% d\n");
	ret1 = ft_printf("% d-m\n", 42);
	ret2 = printf("% d-p\n", 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03.2d\n");
	ret1 = ft_printf("%03.2d-m\n", -2);
	ret2 = printf("%03.2d-p\n", -2);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03.2d\n");
	ret1 = ft_printf("%03.2d-m\n", 1);
	ret2 = printf("%03.2d-p\n", 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03.2d\n");
	ret1 = ft_printf("%03.2d-m\n", 0);
	ret2 = printf("%03.2d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2d\n");
	ret1 = ft_printf("%.2d-m\n", -2);
	ret2 = printf("%.2d-p\n", -2);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.10d\n");
	ret1 = ft_printf("%.10d-m\n", -42);
	ret2 = printf("%.10d-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05d\n");
	ret1 = ft_printf("%05d-m\n", -42);
	ret2 = printf("%05d-p\n", -42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%02d\n");
	ret1 = ft_printf("%02d-m\n", 0);
	ret2 = printf("%02d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.d\n");
	ret1 = ft_printf("%5.d-m\n", 7);
	ret2 = printf("%5.d-p\n", 7);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.1d\n");
	ret1 = ft_printf("%5.1d-m\n", 0);
	ret2 = printf("%5.1d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.d\n");
	ret1 = ft_printf("%5.d-m\n", 0);
	ret2 = printf("%5.d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05d\n"); //precision dictates if 0 is present or not. CHANGE!!
	ret1 = ft_printf("%05d-m\n", 0);
	ret2 = printf("%05d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05.d\n");
	ret1 = ft_printf("%05.d-m\n", 0);
	ret2 = printf("%05.d-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05i\n");
	ret1 = ft_printf("%05i-m\n", 0);
	ret2 = printf("%05i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5i\n");
	ret1 = ft_printf("%-5i-m\n", 0);
	ret2 = printf("%-5i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5.3i\n");
	ret1 = ft_printf("%-5.3i-m\n", 0);
	ret2 = printf("%-5.3i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%10i\n");
	ret1 = ft_printf("%10i-m\n", 0);
	ret2 = printf("%10i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-i\n");
	ret1 = ft_printf("%-i-m\n", 0);
	ret2 = printf("%-i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03i\n");
	ret1 = ft_printf("%03i-m\n", 0);
	ret2 = printf("%03i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	
	printf("TEST %%+10i\n");
	ret1 = ft_printf("%+10i-m\n", 1002);
	ret2 = printf("%+10i-p\n", 1002);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%+i\n");
	ret1 = ft_printf("%+i-m\n", -8);
	ret2 = printf("%+i-p\n", -8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	
	printf("TEST %% i\n");
	ret1 = ft_printf("% i-m\n", -8);
	ret2 = printf("% i-p\n", -8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 2i\n");
	ret1 = ft_printf("% 2i-m\n", 8);
	ret2 = printf("% 2i-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+2i\n");
	ret1 = ft_printf("%+2i-m\n", 8);
	ret2 = printf("%+2i-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+i\n");
	ret1 = ft_printf("%+i-m\n", 0);
	ret2 = printf("%+i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	
	printf("TEST %% i\n");
	ret1 = ft_printf("% i-m\n", 0);
	ret2 = printf("% i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05i\n");
	ret1 = ft_printf("%05i-m\n", 0);
	ret2 = printf("%05i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+4i\n");
	ret1 = ft_printf("%+4i-m\n", 0);
	ret2 = printf("%+4i-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05i\n");
	ret1 = ft_printf("%05i-m\n", 7);
	ret2 = printf("%05i-p\n", 7);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05i\n");
	ret1 = ft_printf("%d %d %d %d gg!-m\n", 1, -2, 33, 42);
	ret2 = printf("%d %d %d %d gg!-p\n", 1, -2, 33, 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	
	//unsigned short int in = 65536;
	/*printf("TEST %%lld\n");  
	ret1 = ft_printf("%hu-m\n", (unsigned short)65536);
	ret2 = printf("%hu-p\n", (unsigned short)65536);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);*/

	printf("TEST %%05i\n");
	ret1 = ft_printf("%ld-m\n", (long)INT_MAX + 1);
	ret2 = printf("%ld-p\n", (long)INT_MAX + 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05i\n");
	ret1 = ft_printf("%ld-m\n", LONG_MIN);
	ret2 = printf("%ld-p\n", LONG_MIN);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%*.(-3)*i\n");
	ret1 = ft_printf("%*.*d-m\n", -15, -15, 42);
	ret2 = printf("%*.*d-p\n",-15, -15, 42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

printf("############ %%u ######################\n");

	printf("TEST %%8.3u\n");
	ret1 = ft_printf("%8.3u-m\n", 0);
	ret2 = printf("%8.3u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%8.u\n");
	ret1 = ft_printf("%8.u-m\n", 0);
	ret2 = printf("%8.u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.1u\n");
	ret1 = ft_printf("%5.1u-m\n", 0);
	ret2 = printf("%5.1u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", (unsigned)4294967296);
	ret2 = printf("%u-p\n", (unsigned)4294967296);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", -1);
	ret2 = printf("%u-p\n", -1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%02u\n");
	ret1 = ft_printf("%02u-m\n", 0);
	ret2 = printf("%02u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%5.3u\n");
	ret1 = ft_printf("%5.3u-m\n", 0);
	ret2 = printf("%5.3u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.1u\n");
	ret1 = ft_printf("%5.1u-m\n", 0);
	ret2 = printf("%5.1u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%5.u\n");
	ret1 = ft_printf("%5.u-m\n", 0);
	ret2 = printf("%5.u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05u\n"); //precision dictates if 0 is present or not. CHANGE!!
	ret1 = ft_printf("%05u-m\n", 0);
	ret2 = printf("%05u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05.u\n");
	ret1 = ft_printf("%05.u-m\n", 0);
	ret2 = printf("%05.u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%05u\n");
	ret1 = ft_printf("%05u-m\n", 0);
	ret2 = printf("%05u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5u\n");
	ret1 = ft_printf("%-5u-m\n", 0);
	ret2 = printf("%-5u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%-5.3u\n");
	ret1 = ft_printf("%-5.3u-m\n", 0);
	ret2 = printf("%-5.3u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%10u\n");
	ret1 = ft_printf("%10u-m\n", 0);
	ret2 = printf("%10u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-u\n");
	ret1 = ft_printf("%-u-m\n", 0);
	ret2 = printf("%-u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03u\n");
	ret1 = ft_printf("%03u-m\n", 0);
	ret2 = printf("%03u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	
	printf("TEST %%-10u\n");
	ret1 = ft_printf("%-10u-m\n", 1002);
	ret2 = printf("%-10u-p\n", 1002);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", 8);
	ret2 = printf("%u-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	
	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", 8);
	ret2 = printf("%u-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%2u\n");
	ret1 = ft_printf("%2u-m\n", 8);
	ret2 = printf("%2u-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%2u\n");
	ret1 = ft_printf("%2u-m\n", 8);
	ret2 = printf("%2u-p\n", 8);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", 10000000);
	ret2 = printf("%u-p\n", 10000000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	
	printf("TEST %%u\n");
	ret1 = ft_printf("%u-m\n", 0);
	ret2 = printf("%u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05u\n");
	ret1 = ft_printf("%05u-m\n", 0);
	ret2 = printf("%05u-p\n", 0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	unsigned int t = 4294967295;
	printf("TEST %%2u\n");
	ret1 = ft_printf("%2u-m\n", t);
	ret2 = printf("%2u-p\n", t);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("############ %%p ######################\n");

	int i = 45;
	char c = 'p';
	char *str = "this is a string";

	printf("TEST %%p\n");
	ret1 = ft_printf("%p-m\n", &i);
	ret2 = printf("%p-p\n", &i);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%p\n");
	ret1 = ft_printf("%p-m\n", &c);
	ret2 = printf("%p-p\n", &c);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%p\n");  
	ret1 = ft_printf("%p-m\n", str);
	ret2 = printf("%p-p\n", str);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.p\n");  
	ret1 = ft_printf("%.p-m\n", NULL);
	ret2 = printf("%.p-p\n", NULL);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.p\n");  
	ret1 = ft_printf("%.p-m\n", str);
	ret2 = printf("%.p-p\n", str);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%p\n");  
	ret1 = ft_printf("%p-m\n", NULL);
	ret2 = printf("%p-p\n", NULL);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%20p\n");  
	ret1 = ft_printf("%20p-m\n", str);
	ret2 = printf("%20p-p\n", str);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-20p\n");  
	ret1 = ft_printf("%-20p-m\n", str);
	ret2 = printf("%-20p-p\n", str);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	/*printf("TEST %%.(-3)*p\n");  
	ret1 = ft_printf("%.*p-m\n", -3, NULL);
	ret2 = printf("%.*p-p\n", -3, NULL);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);*/
	
	//printf("TEST %%.5p\n");  
	//ret1 = ft_printf("%.5p-m\n", NULL);
	//ret2 = printf("%.5p-p\n", NULL);
	//printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("############ %%f ######################\n");
	
	printf("TEST %%10.f %%10.0f %%10.15Lf\n");
	ret1 = ft_printf("%10.f %10.0f %10.15Lf-m\n", -3.500000, -3.500000, -3.500000L);
	ret2 = printf("%10.f %10.0f %10.15Lf-p\n", -3.500000, -3.500000, -3.500000L);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#.f %%#.0f %%#.15Lf\n");
	ret1 = ft_printf("%#.f %#.0f %#.15Lf-m\n", -3.500000, -3.500000, -3.500000L);
	ret2 = printf("%#.f %#.0f %#.15Lf-p\n", -3.500000, -3.500000, -3.500000L);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#.f %%#.0f %%#.15Lf\n");
	ret1 = ft_printf("%#.f %#.0f %#.15Lf-m\n", 1.500000, 1.500000, 1.500000L);
	ret2 = printf("%#.f %#.0f %#.15Lf-p\n", 1.500000, 1.500000, 1.500000L);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%#.f %%#.0f %%#.15Lf\n");
	ret1 = ft_printf("%#.f %#.0f %#.15Lf-m\n", (double)0, 4.0, 4.5L);
	ret2 = printf("%#.f %#.0f %#.15Lf-p\n", (double)0, 4.0, 4.5L);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.f\n");
	ret1 = ft_printf("%.f-m\n", 3.9);
	ret2 = printf("%.f-p\n", 3.9);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%10.f\n");
	ret1 = ft_printf("%10.f-m\n", (double)-2);
	ret2 = printf("%10.f-p\n", (double)-2);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%0#10.1f\n");
	ret1 = ft_printf("%0#10.1f-m\n", -0.0f);
	ret2 = printf("%0#10.1f-p\n", -0.0f);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.f\n");
	ret1 = ft_printf("%.ff-m\n", 0.0f);
	ret2 = printf("%.ff-p\n", 0.0f);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%f\n");
	ret1 = ft_printf("%f-m\n", -0.000000);
	ret2 = printf("%f-p\n", -0.000000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.f\n");
	ret1 = ft_printf("%.f-m\n", (double)4);
	ret2 = printf("%.f-p\n", (double)4);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+0f\n");
	ret1 = ft_printf("%+0f-m\n", -0.005000);
	ret2 = printf("%+0f-p\n", -0.00500);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%f\n");
	ret1 = ft_printf("%f-m\n", 10.000000);
	ret2 = printf("%f-p\n", 10.000000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");
	ret1 = ft_printf("%.1f-m\n", -0.750000);
	ret2 = printf("%.1f-p\n", -0.750000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");
	ret1 = ft_printf("%.1f-m\n", 2.750000);
	ret2 = printf("%.1f-p\n", 2.750000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST {%%f}{%%lf}{%%Lf}\n");
	ret1 = ft_printf("{%f}{%lf}{%Lf}-m\n", 1444565444646.646542424224, 1444565444646.646542424224, 1444565444646.646542424224l);
	ret2 = printf("{%f}{%lf}{%Lf}-p\n", 1444565444646.646542424224, 1444565444646.646542424224, 1444565444646.646542424224l);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST {%%f}{%%lf}{%%Lf}\n");
	ret1 = ft_printf("{%f}{%lf}{%Lf}-m\n", 1.42, 1.42, 1.42l);
	ret2 = printf("{%f}{%lf}{%Lf}-p\n", 1.42, 1.42, 1.42l);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%f\n");
	ret1 = ft_printf("%f-m\n", 1.42);
	ret2 = printf("%f-p\n", 1.42);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");
	ret1 = ft_printf("%.1f-m\n", 2.8500000);
	ret2 = printf("%.1f-p\n", 2.8500000);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");
	ret1 = ft_printf("%.1f-m\n", 0.04);
	ret2 = printf("%.1f-p\n", 0.04);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");
	ret1 = ft_printf("%.1f-m\n", 0.0);
	ret2 = printf("%.1f-p\n", 0.0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%f\n");
	ret1 = ft_printf("%f-m\n", 0.0);
	ret2 = printf("%f-p\n", 0.0);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.3f\n");
	ret1 = ft_printf("%.3f-m\n", 0.0005);
	ret2 = printf("%.3f-p\n", 0.0005);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%f\n");
	ret1 = ft_printf("%f-m\n", 2.5555545);
	ret2 = printf("%f-p\n", 2.5555545);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 03f\n");
	ret1 = ft_printf("% 03f-m\n", 42.);
	ret2 = printf("% 03f-p\n", 42.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 04f\n");
	ret1 = ft_printf("% 04f-m\n", -42.);
	ret2 = printf("% 04f-p\n", -42.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%03f\n");
	ret1 = ft_printf("%03f-m\n", 42.);
	ret2 = printf("%03f-p\n", 42.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 04f\n");
	ret1 = ft_printf("% 04f-m\n", 42.);
	ret2 = printf("% 04f-p\n", 42.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% 03f\n");
	ret1 = ft_printf("% 03f-m\n", 0.);
	ret2 = printf("% 03f-p\n", 0.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% f\n");
	ret1 = ft_printf("% f-m\n", -42.);
	ret2 = printf("% f-p\n", -42.);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%6.2f\n");  
	ret1 = ft_printf("%6.2f-m\n", (float)-2.15);
	ret2 = printf("%6.2f-p\n",  (float)-2.15);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%+05f\n");  
	ret1 = ft_printf("%+05f-m\n", (float)2.15);
	ret2 = printf("%+05f-p\n",  (float)2.15);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05f\n");  
	ret1 = ft_printf("%05f-m\n", (float)2.15);
	ret2 = printf("%05f-p\n",  (float)2.15);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05.f\n");  
	ret1 = ft_printf("%05.f-m\n", (float)-2.15);
	ret2 = printf("%05.f-p\n",  (float)-2.15);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.85);
	ret2 = printf("%.1f-p\n",  (float)2.85);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.25);
	ret2 = printf("%.1f-p\n",  (float)2.25);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.35);
	ret2 = printf("%.1f-p\n",  (float)2.35);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.45);
	ret2 = printf("%.1f-p\n",  (float)2.45);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.55);
	ret2 = printf("%.1f-p\n",  (float)2.55);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.95);
	ret2 = printf("%.1f-p\n",  (float)2.95);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.65);
	ret2 = printf("%.1f-p\n",  (float)2.65);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n",  (float)2.75);
	ret2 = printf("%.1f-p\n",  (float)2.75);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n", (float)-2.15834637);
	ret2 = printf("%.2f-p\n",  (float)-2.15834637);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)-2.85999);
	ret2 = printf("%.2f-p\n",  (float)-2.85999);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)-2.25049);
	ret2 = printf("%.2f-p\n",  (float)-2.2549);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)2.35);
	ret2 = printf("%.2f-p\n",  (float)2.35);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)2.45);
	ret2 = printf("%.2f-p\n",  (float)2.45);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)2.55);
	ret2 = printf("%.2f-p\n",  (float)2.55);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)2.95);
	ret2 = printf("%.2f-p\n",  (float)2.95);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.2f\n");  
	ret1 = ft_printf("%.2f-m\n",  (float)2.65);
	ret2 = printf("%.2f-p\n",  (float)2.65);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.33f\n");  
	ret1 = ft_printf("%.33Lf-m\n",  (long double)2.3647824709240924892489042722749247247874);
	ret2 = printf("%.33Lf-p\n",  (long double)2.3647824709240924892489042722749247247874);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.19f\n");  
	ret1 = ft_printf("%.19f-m\n",  (float)2.025);
	ret2 = printf("%.19f-p\n",  (float)2.025);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%.15f\n");  
	ret1 = ft_printf("%.15f-m\n", 1.17549435E-10);
	ret2 = printf("%.15f-p\n",  1.17549435E-10);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("TEST %%.1f\n");  
	ret1 = ft_printf("%.1f-m\n", 99.99);
	ret2 = printf("%.1f-p\n",  99.99);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	printf("############ %% ######################\n\n");
	
	printf("TEST %%5%%\n");  
	ret1 = ft_printf("%5%-m\n");
	ret2 = printf("%5%-p\n");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05%%\n");  
	ret1 = ft_printf("%05%-m\n");
	ret2 = printf("%05%-p\n");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%-05%%\n");  
	ret1 = ft_printf("%-05%-m\n");
	ret2 = printf("%-05%-p\n");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%05.10%%\n");  
	ret1 = ft_printf("%05.10%-m\n");
	ret2 = printf("%05.10%-p\n");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %% .10%%\n");  
	ret1 = ft_printf("% .10%-m\n");
	ret2 = printf("% .10%-p\n");
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);

	printf("############ * ######################\n\n");

	printf("TEST %%*d\n");  
	ret1 = ft_printf("%*d-m\n", 3, 1);
	ret2 = printf("%*d-p\n", 3, 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%*(-6).*(3)d\n");  
	ret1 = ft_printf("%*.*d-m\n", -6, 3, 1);
	ret2 = printf("%*.*d-p\n", -6, 3, 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%*(6).*(3)d\n");  
	ret1 = ft_printf("%*.*d-m\n", 6, 3, 1);
	ret2 = printf("%*.*d-p\n", 6, 3, 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	/*printf("TEST %%(3)*3d\n");  
	//ret1 = ft_printf("%.4hhid-m\n", 3, 1);
	ret2 = printf("%*d-p\n", 3, 1);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);*/
	
	/*printf("############hh######################\n\n");
	
	printf("TEST %%hx\n");  
	ret1 = ft_printf("%hx-m\n", (unsigned short)21);
	ret2 = printf("%hx-p\n", (unsigned short)21);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%hd\n");  
	ret1 = ft_printf("%hd-m\n", -32769);
	ret2 = printf("%hd-p\n", (short)-32769);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("TEST %%hd\n");  
	ret1 = ft_printf("%hd-m\n", -32769);
	ret2 = printf("%lu-p\n", -32769);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	*/
	printf("############ MIXED TYPE ######################\n\n");
	
	printf("TEST %%lu %%lo\n");  
	ret1 = ft_printf("%lu %lo-m\n", 0ul, ULONG_MAX);
	ret2 = printf("%lu %lo-p\n", 0ul, ULONG_MAX);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	printf("############ERROR######################\n\n");
	
	ft_printf("%*p%-135.109d\n", -15,(void*)15603137398285451084lu, 1482420587);
	printf("%*p%-135.109d\n", -15,(void*)15603137398285451084lu, 1482420587);
	
	printf("TEST %%%% %% \n");  
	ret1 = ft_printf("%% %\n");
	printf("\nexpected = -1  output = %d\n\n", ret1);


	//printf("%-48p%-164c" ,(void*)9888845855039847185lu,114);
	//printf("%104.60s%109c%-9p" ,"}&@/h\n\f<C",36,(void*)14251011342640672780lu);
	//printf("%131p%--.42u%65c%-68c%-7c" ,(void*)14631880201060661778lu,1668628755u,110,-16,-32);
	//ft_printf("%--158p%---.15s%-108c" ,(void*)9474372414016659745lu,"O_r",24);
	//printf("%64p%038.87d%23c%--182.49i%--76.110%" ,(void*)10278319775164267212lu,-1550079501,30,-862355787);
	//printf("%-102p%-91p%00*.32%" ,(void*)17383623580121946936lu,(void*)6825043625903153404lu,-125);
	//printf("%120p%--55.128i" ,(void*)9377650025287837451lu,816352753);
	//printf("%000169.50u%-127.85%%--195p%-51.49s%-160p" ,2209242471u,(void*)8769599610347160825lu,"1+6UGQiBr8wAmIE*{,xBrju#}s=X",(void*)15118044339110535138lu);
	//printf("%57c%-76.*s%--38p%-*.159X%000193.93X" ,55,-20,"@(ECnQ^2yp,6x4F\fwA*iLS\fgt,De",(void*)15808961691193129302lu,168,1914174653u,2368364743u);
	//printf("%29p%0151.162x%---53.46u%-139.26X" ,(void*)17894711340605174765lu,1565093748u,662758369u,3536629372u);
	//printf("%--74.144x%-166p%--78.55s%-195.140x" ,625771587u,(void*)14083163232330204447lu,"P(LiM1QG='.bUp\r",314220770u);
	//printf("%-66p%-90c%--*.69x%0045.*u" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u);
	//printf("%108p%-175.188i" ,(void*)11721873312409420167lu,-653373315);

	return (0);
}


