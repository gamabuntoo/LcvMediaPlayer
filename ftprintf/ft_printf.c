/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:10:03 by gule-bat          #+#    #+#             */
/*   Updated: 2024/12/20 16:48:02 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_converter(const char c, va_list ar, int *ct)
{
	if (c == 'c')
		ft_putcharpimp(va_arg(ar, int), ct);
	if (c == 's')
		ft_putstr_pimp(va_arg(ar, char *), ct);
	if (c == 'p')
		ft_adress(va_arg(ar, unsigned long long int), ct);
	if (c == 'd' || c == 'i')
		ft_putnbr_pimp(va_arg(ar, int), ct, 0);
	if (c == 'u')
		ft_putnbr_pimp(va_arg(ar, unsigned int), ct, 1);
	if (c == 'x')
		ft_hextech(va_arg(ar, unsigned long long), ct, 2);
	if (c == 'X')
		ft_hextech(va_arg(ar, unsigned long long), ct, 1);
	if (c == '%')
		ft_putcharpimp('%', ct);
}

int	checkarg(char a)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i'
		|| a == 'u' || a == 'x' || a == 'X' || a == '%')
		return (1);
	else
		return (0);
}

void	ft_putcharpimp(char c, int *ct)
{
	ft_putchar_fd(c, 1);
	*ct += 1;
}

void	ft_initi(t_list *list)
{
	list->i = 0;
	list->ctp = 0;
	list->counter = 0;
}

int	ft_printf(const char *st, ...)
{
	int		*ctfinal;
	va_list	args;
	t_list	values;

	ft_initi(&values);
	ctfinal = &values.counter;
	va_start(args, st);
	if (!st || (st[0] == '0' && !st[values.i + 1]))
		return (ft_putchar_fd('0', 1), 1);
	if (ft_whiloop(&values, ctfinal, args, (char *)st) < 0)
		return (-1);
	else
		return ((values.i - (values.ctp * 2)) + *ctfinal);
}

// #include <stdio.h>
// // #define GREEN "\033[32m"
// // #define RESET "\033[0m"
// // #define YELLOW "\033[34m"

// // void    testpf(void);
// // void	pacoc(void);

// int	main()
// {
// // 	//int		i;
// // 	//i = 0;
// //     //i = ft_printf("%%%");
// //     //ft_printf("\n");
// // 	//printf("%d\n", i);
// //     //i = printf("%%%");
// // 	//printf("%d\n", i);
// 	int x = 0;
// // 	int y = 0;

// //	x = ft_printf(" %x ", 0);
// 	x = ft_printf("%%%");
// 	printf("\n%i\n", x);
// 	x = printf("%%%");
// 	printf("\n%i\n", x);
// 	x = ft_printf("%c ", 'c');
// 	//x = ft_printf("%%%");
//    // x = printf("%%%");	
// 	printf("\n%i\n", x);
//     //x = ft_printf("%%%");
// 	//printf("%i\n", x);
// 	return (1);
// //	y = printf(" %x ", 0);
// 	//printf("%i faux || %i vrai \n", x, y);
// //	if (x == y)
// //		printf("%sSUCESS size hexa%s\n", GREEN, RESET);

// //	x = ft_printf(" %x ", -9223372036854775808);
// //    ft_printf("\n");
// //	y = printf(" %x ", -9223372036854775808);
// //    ft_printf("\n");
// //	printf("%i faux || %i vrai \n", x, y);
// //	if (x == y)
// //		printf("%sSUCESS size hexa%s\n", GREEN, RESET);

// //    ft_printf("\n");
// //	y = ft_printf("%c %s %d %i %u %x %X %% %c %s %d %i %u 
// //	%x %X %% %c %s %d %i %u %x %X %c", 'A', "42", 42, 42 ,42 , 42, 42, 'B', 
// //	"-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// //    ft_printf("\n");
// //	x = printf("%c %s %d %i %u %x %X %% %c %s %d %i %u 
// //	%x %X %% %c %s %d %i %u %x %X %c", 'A', "42", 42, 42 ,42 , 42, 42, 'B', 
// //	"-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, '\0');
// //	if (x == y)
// //		printf("\nSUCESS multi\n");
// //	printf("%i faux || %i vrai \n", x, y);	
// //	pacoc();
// //	pacos();

//     return (0);
// }
// // // /*
// // void	pacos(void)
// {
// 	static int ct;
// 	int x;
// 	x = 0;
// 	int y;
// 	y = 0;	
// 	if (ct == 9)
// 		ft_printf("CHAR PART DONE\n");	
// }
// void	pacoc(void)
// {
// 	static int ct;
// 	int x;
// 	x = 0;
// 	int y;
// 	y = 0;
// 	printf("%s", YELLOW);
// 	x = ft_printf("%c", 'b');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf("%c", 'b');
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c ", '0');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c ", '0');
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c ", '0' - 256);
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c ", '0' - 256);
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c ", '0' + 256);
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c ", '0' + 256);
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	x = 0;
// 	y = 0;
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c %c %c ", '0' , 0, '1');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c %c %c ", '0' , 0, '1');
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	x = 0;
// 	y = 0;
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c %c %c ", ' ', ' ', ' ');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c %c %c ", ' ', ' ', ' ');
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	x = 0;
// 	y = 0;
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c %c %c ", '1', '2', '3');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c %c %c ", '1', '2', '3');
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);
// 	x = 0;
// 	y = 0;
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c %c %c ", '2', '1', 0);
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c %c %c ", '2', '1', 0);
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);

// 	x = 0;
// 	y = 0;
// 	printf("%s", RESET);
// 	printf("%s", YELLOW);
// 	x = ft_printf(" %c %c %c ", '0', '1', '2');
// 	ft_printf("\n");
// 	ft_printf("%i\n", x);
// 	y = printf(" %c %c %c ", '0', '1', '2');
// 	ft_printf("\n");
// 	ft_printf("%i\n", y);
// 	if (x == y)
// 		printf("%sSUCESS test %i\n", GREEN, ct++);
// 	ft_printf("\n\n");
// 	printf("%s", RESET);	
// 	if (ct == 5)
// 		ft_printf("CHAR PART DONE\n");
// }
// void    testpf(void)
// {
//     char c = 'c';
//     char *s = "test string";
//     void *v = "test void";
//     int de = -1254;
//     int i = 1254;
//     unsigned int u = 254587;

//     ft_printf("%c char unique\n", c);
//     printf("%c char unique\n", c);
//     ft_printf("%s string\n", s);
//     printf("%s string\n", s);
//     ft_printf("%p void hexa\n", v);
//     printf("%p void hexa\n", v);
//     ft_printf("%p int hexa\n", (void *)i);
//     printf("%p int hexa\n", (void *)i);
//     ft_printf("%d int quelconque\n", de);
//     printf("%d int quelconque\n", de);
//     ft_printf("%d int max\n", -2147483648);
//     printf("%d int max\n", -2147483648);
//     ft_printf("%d int max\n", 2147483647);
//     printf("%d int max\n", 2147483647);
//     ft_printf("%d int quelconque negatif\n", de);
//     printf("%d int quelconque negatif\n", de);
//     ft_printf("%i integer b10\n", 'x7n9');
//     printf("%i integer b10\n", 'x7n9');
//     ft_printf("%u unsigned\n", u);
//     printf("%u unsigned\n", u);
//     ft_printf("%x hexa min\n", c);
//     printf("%x hexa min\n", c);
//     ft_printf("%X hexa maj\n", i);
//     printf("%X hexa maj\n", i);
//     ft_printf("%% pourcent\n");
//     printf("%% pourcent\n");
//     ft_printf("\n");
//     ft_printf(0);
//     ft_printf("\n");
//     printf(0);
//     ft_printf("\n");
//     ft_printf("\tfin test pf");
//     ft_printf("\n");
//     ft_printf("\n");
// }*/
