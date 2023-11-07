/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:13:40 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/01 20:38:12 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct		s_vars
{
	char	**res;
	int		s_word;
	size_t	i;
	size_t	j;
};

static void	*ft_free(char **s)
{
	char	**temp;

	temp = s;
	while (*s)
		free(*s++);
	free(temp);
	return (NULL);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	struct s_vars	st;

	st.res = NULL;
	st.s_word = -1;
	st.i = 0;
	st.j = 0;
	st.res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!st.res)
		return (NULL);
	while (st.i <= ft_strlen(s))
	{
		if (s[st.i] != c && (st.s_word == -1 || st.s_word < 0))
			st.s_word = st.i;
		else if ((s[st.i] == c || st.i == ft_strlen(s)) && st.s_word >= 0)
		{
			st.res[st.j] = ft_substr(s, st.s_word, st.i - st.s_word);
			if (!st.res[st.j])
				return (ft_free(st.res));
			st.s_word = -1;
			st.j++;
		}
		st.i++;
	}
	return (st.res);
}
