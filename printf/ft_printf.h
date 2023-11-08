/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:55:30 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/08 17:55:30 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_print_string(va_list args);
int		ft_putnbr_base(unsigned int nb, char *base);
int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_decimal(va_list args);
int		ft_print_unsigned_decimal(va_list args);
int		ft_print_hexadecimal(va_list args, char c);
int		ft_print_percent(void);

#endif