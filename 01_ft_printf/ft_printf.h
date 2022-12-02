/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 19:12:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printchar(int c, int *count);
int		ft_printpercent(void);
int		ft_lenptr(unsigned long num);
void	ft_printstr(char *str, int *count);
void	ft_putptr(unsigned long num, int *count);
void	ft_printptr(unsigned long long ptr, int *count);
//int		ft_printnb(int num);
void	ft_print_unsigned(unsigned int num, int *count);
void	check_arg(va_list args, char arg, int *count);
//int		ft_lenhex(unsigned int num, int base);
void	ft_printbase(int num, char *format, int base, int *count);

#endif
