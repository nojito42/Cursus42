/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:05:11 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/14 21:05:32 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
int	ft_print_string(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1,str,ft_strlen(str));
	return (len);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= ft_strlen(base))
		len += ft_putnbr_base(nb / ft_strlen(base), base);
	len += write(2,&base[nb % ft_strlen(base)],1);
	return (len);
}
