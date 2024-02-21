/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojito <nojito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:26:53 by jmoulin           #+#    #+#             */
/*   Updated: 2024/02/21 15:23:24 by nojito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *format, struct s_vars *v)
{
	while (*format)
	{
		if (*format == '%' && contains(*(format + 1), FLAGS))
		{
			v->flag = *(format + 1);
			format++;
			if (contains(v->flag, "cs"))
				print_sc(v);
			else if (contains(v->flag, "pxX"))
				print_px(v);
			else if (contains(v->flag, "id"))
				v->cnt += putnbr_id(va_arg(v->args, int), "0123456789");
			else if (contains(v->flag, "u"))
				v->cnt += putnbr_upx(v, va_arg(v->args, uint32_t),
						"0123456789");
			else
				v->cnt += write(1, "%%", 1);
		}
		else
			v->cnt += write(1, format, 1);
		if (v->cnt < 0)
			break ;
		format++;
	}
	return (v->cnt);
}

int	ft_printf(const char *format, ...)
{
	struct s_vars	v;

	v.cnt = 0;
	va_start(v.args, format);
	if (ft_parse(format, &v) < 0)
		return (-1);
	va_end(v.args);
	return (v.cnt);
}
