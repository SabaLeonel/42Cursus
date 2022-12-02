/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/30 19:27:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_printchar(int c);
int		ft_printpercent(void);
int		ft_lenptr(unsigned long num);
int		ft_printstr(char *str);
void	ft_putptr(unsigned long num);
int		ft_printptr(unsigned long long ptr);
int		ft_printnb(int num);
int		ft_print_unsigned(unsigned int num);
int		check_arg(va_list args, char arg);
int		ft_lenhex(unsigned int num);
int		ft_printhex(unsigned long long num, char *format, int base);

#endif
