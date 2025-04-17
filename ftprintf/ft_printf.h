/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:55:40 by gule-bat          #+#    #+#             */
/*   Updated: 2024/12/20 16:48:57 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int		i;
	int		counter;
	int		ctp;
}				t_list;

int		ft_whiloop(t_list *ints, int *ct, va_list ar, char *st);
int		ft_printf(const char *st, ...);
int		ft_freelen(void	*ptr);
int		checkarg(char a);
int		length(unsigned long long int n);
void	ft_putcharpimp(char c, int *ct);
void	ft_converter(const char c, va_list ar, int *ct);
void	assign_nb(char *str, unsigned long long int n, int i);
void	ft_putnbr_pimp(long int nb, int *ct, int u);
void	ft_adress(unsigned long long p, int *c);
void	ft_putstr_pimp(char *str, int *c);
void	ft_hextech(unsigned int x, int *c, int r);
char	*ft_hex_to_asc(unsigned long long int n, int s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *s);
int		ft_isalpha(int c);

#endif
