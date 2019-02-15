/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/15 17:46:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				srcrpl(char *s, char a, char b)
{
	while (*s)
		if (*s++ == a)
			*(s - 1) = b;
	return (1);
}

void			result_preparation(va_list ap)
{
	if (s_data.specifier == 'd' || s_data.specifier == 'i')
		print_digits(ap);
	else if (s_data.specifier == 'u')
		print_unsigned_digits(ap);
	else if (s_data.specifier == 'o')
		print_octal(ap);
	else if(s_data.specifier == '%')
		print_char('%');
	else if (s_data.specifier == 'c')
		print_char(va_arg(ap, int));
	else if (s_data.specifier == 's')
		print_string(va_arg(ap, char *));
}
