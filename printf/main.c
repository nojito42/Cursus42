/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojito <nojito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:23:58 by jmoulin           #+#    #+#             */
/*   Updated: 2024/02/20 18:57:22 by nojito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("salut je m'appelle %s %s et j'ai %d an(s)a ssss\n", "Jon",
		"Moulin", 39);
	ft_printf("Hello %c\n", 'W');
	ft_printf("Hello %d\n", 322222);
	ft_printf("Hello %i\n", 42);
	ft_printf("Hello %u\n", 42);
	ft_printf("Hello %p\n", 012324123);
	ft_printf("Hello %X\n", 42);
	ft_printf("Hello %p\n", 42);
	ft_printf("Hello %%\n");
	ft_printf("Hello %% %-%%%%%i %d\n", 42, 42342);
	return (0);
}
