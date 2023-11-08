/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:20:36 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/08 20:20:36 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_parse_format(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_print_char(args);
	else if (format[i] == 's')
		count += ft_print_string(args);
	else if (format[i] == 'p')
		count += ft_print_pointer(args);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_print_decimal(args);
	else if (format[i] == 'u')
		count += ft_print_unsigned_decimal(args);
	else if (format[i] == 'x' || format[i] == 'X')
		count += ft_print_hexadecimal(args, format[i]);
	else if (format[i] == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse_format(format, i, args);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	ft_printf("Hello %s\n", "World");
	ft_printf("Hello %c\n", 'W');
	ft_printf("Hello %d\n", 42);
	ft_printf("Hello %i\n", 42);
	ft_printf("Hello %u\n", 42);
	ft_printf("Hello caca %x\n", 0xaaff);
	ft_printf("Hello %X\n", 42);
	ft_printf("Hello %p\n", 42);
	ft_printf("Hello %%\n");
	return (0);
}*/