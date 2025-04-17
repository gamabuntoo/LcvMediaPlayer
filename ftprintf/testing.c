/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:10:03 by gule-bat          #+#    #+#             */
/*   Updated: 2024/12/20 16:47:35 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_adress(unsigned long long p, int *c)
{
	char	*str;

	str = NULL;
	if (!p)
		return (ft_putstr_pimp("(nil)", c));
	ft_putstr_fd("0x", 1);
	(*c) += 2;
	str = ft_hex_to_asc(p, 0);
	ft_putstr_fd(str, 1);
	(*c) += ft_freelen(str);
}

void	ft_putstr_pimp(char *str, int *c)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_putstr_pimp("(null)", c));
	while (str[i])
	{
		ft_putcharpimp(str[i], c);
		i++;
	}
}

void	ft_hextech(unsigned int x, int *c, int r)
{
	char	*st;
	int		i;

	st = NULL;
	i = 0;
	if (x <= 0)
		ft_putcharpimp('0', c);
	if (!x)
		return ;
	st = ft_hex_to_asc(x, r);
	if (!st)
		return ;
	while (st[i])
	{
		ft_putcharpimp(st[i], c);
		i++;
	}
	free(st);
}

int	ft_whiloop(t_list *ints, int *ct, va_list ar, char *st)
{
	while (st[ints->i])
	{
		if ((st[ints->i] == '%' && (checkarg(st[ints->i + 1]) == 1)))
		{
			ints->ctp += 1;
			ft_converter(st[ints->i + 1], ar, ct);
			ints->i += 2;
		}
		else if (st[ints->i] == '%')
			ints->i++;
		else if (st[ints->i] != '\0' && st[ints->i] != '%')
		{
			ft_putchar_fd(st[ints->i], 1);
			ints->i++;
		}
	}
	return (1);
}
/*if (x < 0)
return (ft_putcharpimp('0', c));*/
/*void	ft_conv(va_list arg, int i, int *ct)
{
	char					c;
	char					*str;
	unsigned long long int	p;
	int						di;

	ft_init(&c, &str, &p, &di);
	if (i == 1)
		ft_putcharpimp(c, arg, ct);
	if (i == 2)
		ft_putstr_pimp(str, arg, ct);
	if (i == 3)
		ft_adress(p, ct, arg);
	if (i == 4)
		ft_putnbr_pimp(di = va_arg(arg, int), ct, 0);
	if (i == 5)
		ft_putnbr_pimp(p = va_arg(arg, unsigned long long), ct, 1);
	if (i == 6)
		ft_hextech(p, arg, ct, 2);
	if (i == 7)
		ft_hextech(p, arg, ct, 1);
	if (i == 8)
		ft_putcharpimp('%', 0, ct);
}

void	ft_init(char *c, char **str, unsigned long long *p, int *di)
{
	*c = 0;
	*str = NULL;
	*p = 0;
	*di = 0;
}
*/
