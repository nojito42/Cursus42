/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojito <nojito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:24:53 by jmoulin           #+#    #+#             */
/*   Updated: 2024/02/20 22:11:39 by nojito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define FLAGS "cspdiuxX%%"

struct			s_vars
{
	va_list		args;
	char		flag;
	int			cnt;
};

int				contains(char c, char *s);
unsigned long	ft_strlen(const char *s);
void			print_sc(struct s_vars *s);
int				putnbr_id(long long int nb, char *base);
int				putnbr_upx(struct s_vars *v, unsigned long long nb, char *base);
void			print_px(struct s_vars *v);
int				ft_printf(const char *format, ...);

#endif