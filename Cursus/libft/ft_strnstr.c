/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:11:05 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 21:31:34 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (*haystack == '\0' || len < ft_strlen(needle))
		return (NULL);
	if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		return ((char *)haystack);
	return (ft_strnstr(haystack + 1, needle, len - 1));
}
