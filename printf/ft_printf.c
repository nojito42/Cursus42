/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:55 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/14 21:20:55 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(const char *format, int i, struct s_vars *v)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				v->count += ft_print_char(v->args);
			else if (format[i] == 's')
				v->count += ft_print_string(v->args);
			else if (format[i] == 'p')
				v->count += ft_print_pointer(v->args);
			else if (format[i] == 'd' || format[i] == 'i')
				v->count += ft_print_decimal(v->args);
			else if (format[i] == 'u')
				v->count += ft_print_unsigned_decimal(v->args);
			else if (format[i] == 'x' || format[i] == 'X')
				v->count += ft_print_hexadecimal(v->args, format[i]);
			else if (format[i] == '%')
				v->count += write(2, "%%", 1);
		}
		else
			v->count += write(2, &format[i], 1);
		i++;
	}
}
int	ft_printf(const char *format, ...)
{
	t_vars	v;
	int		i;

	i = 0;
	v.count = 0;
	va_start(v.args, format);
	ft_parse(format, i, &v);
	va_end(v.args);
	return (v.count);
}
