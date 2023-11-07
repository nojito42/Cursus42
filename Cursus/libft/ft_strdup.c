/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:13:15 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:13:15 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	s;

	s = ft_strlen(s1) + 1;
	copy = malloc(s);
	if (copy == NULL)
		return (NULL);
	copy[s - 1] = '\0';
	return (ft_memcpy(copy, s1, s));
}
