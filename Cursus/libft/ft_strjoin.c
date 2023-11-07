/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:12:22 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:12:25 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;

	buff = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buff)
		return (buff);
	ft_memcpy(buff, s1, ft_strlen(s1));
	ft_memcpy(buff + ft_strlen(s1), s2, ft_strlen(s2));
	buff[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (buff);
}
