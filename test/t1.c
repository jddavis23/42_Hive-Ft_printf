#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("############ %%s ######################\n");
	
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

printf("############ %%d/i ######################\n");

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
	
	printf("TEST %%p\n");  
	ret1 = ft_printf("%p-m\n", NULL);
	ret2 = printf("%p-p\n", NULL);
	printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	//printf("TEST %%.5p\n");  
	//ret1 = ft_printf("%.5p-m\n", NULL);
	//ret2 = printf("%.5p-p\n", NULL);
	//printf("ft_printf = %d   printf = %d\n\n", ret1, ret2);
	
	return (0);
}