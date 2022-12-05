/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/05 14:33:27 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printchar(int c, int *len);
int		ft_printpercent(void);
void	ft_printstr(char *str, int *len);
void	ft_putptr(size_t num, int *len);
void	ft_printptr(size_t ptr, int *len);
void	ft_print_unsigned(unsigned int num, int *len);
void	check_arg(va_list *args, char arg, int *count, int *len);
void	ft_printbase(long long int num, char *format, int base, int *len);

#endif
