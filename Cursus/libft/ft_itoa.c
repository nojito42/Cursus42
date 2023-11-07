/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:16:29 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:16:29 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct		s_vars
{
	int		is_neg;
	int		len;
	char	*str;
	int		i;
};

int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_strnew(int size)
{
	char	*str;

	if (size < 0)
		return (NULL);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	return (str);
}

void	compute(int n, struct s_vars s)
{
	while (n > 0)
	{
		s.str[s.i] = (n % 10) + '0';
		n /= 10;
		s.i--;
	}
}

char	*ft_itoa(int n)
{
	struct s_vars	s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s.is_neg = 0;
	if (n < 0)
	{
		s.is_neg = 1;
		n = -n;
	}
	s.len = ft_intlen(n);
	s.str = ft_strnew(s.len + s.is_neg);
	if (s.str == NULL)
		return (NULL);
	if (s.is_neg)
		s.str[0] = '-';
	s.i = s.len + s.is_neg - 1;
	compute(n, s);
	return (s.str);
}
