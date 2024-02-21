/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojito <nojito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:27:08 by jmoulin           #+#    #+#             */
/*   Updated: 2024/02/20 22:12:29 by nojito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	contains(char c, char *s)
{
	while (*s && *s != c)
		s++;
	return (*s == c);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	putnbr_id(long long int nb, char *base)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= (long long)ft_strlen(base))
		len += putnbr_id(nb / ft_strlen(base), base);
	len += write(1, &base[nb % ft_strlen(base)], 1);
	return (len);
}

int	putnbr_upx(struct s_vars *v, unsigned long long nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= ft_strlen(base))
		len += putnbr_upx(v, nb / ft_strlen(base), base);
	len += write(1, &base[nb % ft_strlen(base)], 1);
	return (len);
}
