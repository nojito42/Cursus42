/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojito <nojito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:20:21 by jmoulin           #+#    #+#             */
/*   Updated: 2024/02/20 23:24:57 by nojito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sc(struct s_vars *s)
{
	char	*str;
	int		chr;

	if (s->flag == 'c')
	{
		chr = va_arg(s->args, int);
		s->cnt += write(1, &chr, 1);
		return ;
	}
	str = va_arg(s->args, char *);
	if (!str)
		str = "(null)";
	s->cnt += write(1, str, ft_strlen(str));
}

void	print_px(struct s_vars *v)
{
	uintptr_t	ptr;

	ptr = va_arg(v->args, uintptr_t);
	if (v->flag == 'p')
	{
		v->cnt += write(1, "0x", 2);
		v->cnt += putnbr_upx(v, ptr, "0123456789abcdef");
	}
	else
	{
		if (v->flag == 'x')
			v->cnt += putnbr_upx(v, (uint32_t)ptr, "0123456789abcdef");
		else
			v->cnt += putnbr_upx(v, (uint32_t)ptr, "0123456789ABCDEF");
	}
}
