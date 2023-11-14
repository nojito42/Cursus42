/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:17:52 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:17:52 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocatedmem;

	allocatedmem = malloc(size * count);
	if (allocatedmem == NULL)
		return (NULL);
	if (size > 0)
		ft_memset(allocatedmem, 0, count * size);
	return (allocatedmem);
}
