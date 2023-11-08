/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:18:52 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/08 20:18:52 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_print_pointer(va_list args)
{
	unsigned long long	nb;
	int					len;

	nb = va_arg(args, unsigned long long);
	ft_putstr("0x");
	len = ft_putnbr_base(nb, "0123456789abcdef");
	return (len + 2);
}

int	ft_print_decimal(va_list args)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	len = ft_putnbr_base(nb, "0123456789");
	return (len);
}

int	ft_print_unsigned_decimal(va_list args)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	len = ft_putnbr_base(nb, "0123456789");
	return (len);
}

int	ft_print_hexadecimal(va_list args, char c)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	if (c == 'x')
		len = ft_putnbr_base(nb, "0123456789abcdef");
	else
		len = ft_putnbr_base(nb, "0123456789ABCDEF");
	return (len);
}
