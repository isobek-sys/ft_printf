/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:03:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/04 19:18:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%s\n", "Hello, World!!!");
	printf("%*d\n", 5, 8);
	printf("%2$*1$d\n", 5, 8);
	printf("%10.4g\n", 123456789.823);
	printf("%10.4G\n", 123456789.823);
	printf("%o\n", 255);
	printf("%10.3c\n", 'a');
	return (0);
}