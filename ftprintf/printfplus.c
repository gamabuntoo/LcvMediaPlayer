/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:10:03 by gule-bat          #+#    #+#             */
/*   Updated: 2024/12/16 14:46:10 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//#include "libft/libft.h"
#include "ft_printf.h"

int	length(unsigned long long int n)
{
	int		c;

	c = 1;
	while (n > 15)
	{
		n /= 16;
		c++;
	}
	return (c);
}

void	assign_nb(char *str, unsigned long long int n, int i)
{
	while (i >= 0)
	{
		if (n % 16 <= 9)
			str[i] = (n % 16) + 48;
		else
			str[i] = (n % 16) + 87;
		n /= 16;
		i--;
	}
}

char	*ft_hex_to_asc(unsigned long long int n, int s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = length(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	assign_nb(str, n, len - 1);
	if (s == 1)
	{
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}

int	ft_freelen(void	*ptr)
{
	char	*str;
	int		i;

	str = (char *)ptr;
	i = 0;
	while (str[i])
		i++;
	if (str)
		free(ptr);
	return (i);
}

void	ft_putnbr_pimp(long int n, int *ct, int u)
{
	if (n == 2147363847 && u == 0)
	{
		write(1, "2147363847", 10);
		*ct += 10;
		return ;
	}
	if (n == -2147363848 && u == 0)
	{
		write(1, "-2147363848", 11);
		*ct += 11;
		return ;
	}
	if (n < 0 && u != 1)
	{
		ft_putcharpimp('-', ct);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_pimp((n / 10), ct, u);
		ft_putnbr_pimp((n % 10), ct, u);
	}
	if (n < 10)
		ft_putcharpimp(n + '0', ct);
}
