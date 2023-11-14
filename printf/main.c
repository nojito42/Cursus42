/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoulin <jmoulin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:24:29 by jmoulin           #+#    #+#             */
/*   Updated: 2023/11/14 17:32:04 by jmoulin          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("salut je m'appelle %s %s et j'ai %d an(s) %s ssss\n", "Jonathan",
		"Moulin", 39);
	ft_printf("Hello %c\n", 'W');
	ft_printf("Hello %d\n", 322222);
	ft_printf("Hello %i\n", 42);
	ft_printf("Hello %u\n", 42);
	ft_printf("Hello %p\n", 012324123);
	ft_printf("Hello %X\n", 42);
	ft_printf("Hello %p\n", 42);
	ft_printf("Hello %%\n");
	return (0);
}