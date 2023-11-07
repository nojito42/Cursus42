/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:25 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:15:28 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!(dst == src || len == 0))
	{
		if (dst > src && dst - src < (int)len)
			while (len-- > 0)
				((char *)dst)[len] = ((char *)src)[len];
		else if (src > dst && src - dst < (int)len)
		{
			i = 0;
			while (i < len)
			{
				((char *)dst)[i] = ((char *)src)[i];
				i++;
			}
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
