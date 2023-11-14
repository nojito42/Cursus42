/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:21 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/14 21:20:50 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(2, &c, 1));
}

int	ft_print_pointer(va_list args)
{
	return (write(2, "0x", ft_strlen("0x")) + ft_putnbr_base(va_arg(args,
				__intptr_t), "0123456789abcdef"));
}

int	ft_print_decimal(va_list args)
{
	return (ft_putnbr_base(va_arg(args, int), "0123456789"));
}

int	ft_print_unsigned_decimal(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
}

int	ft_print_hexadecimal(va_list args, char c)
{
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
}
