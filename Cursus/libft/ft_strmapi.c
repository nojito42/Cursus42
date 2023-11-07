/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:11:38 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 18:11:38 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*nstr;
	size_t	i;

	nstr = ft_strdup(s);
	if (!nstr)
		return (nstr);
	i = 0;
	while (nstr[i])
	{
		nstr[i] = (*f)(i, nstr[i]);
		i++;
	}
	return (nstr);
}
