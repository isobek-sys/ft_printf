/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:38:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/04 14:51:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int						main(void)
{
	int					my;
	int					sy;
	int					d;
	char				*s;

	d = 0;

	s = "|%20p|\n";

	ft_printf("<<<<<<ft_printf>>>>>>\n");
	my = ft_printf(s, &s);
	ft_printf("<<<<<<printf>>>>>>\n");
	sy = printf(s, &s);
	printf("my = %d sy = %d\n", my, sy);
	return (0);
}
