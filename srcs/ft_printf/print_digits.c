/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:45:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/02/21 10:45:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_put_long_nbr(__int128 d)
{
	if (d > 9 && !(ft_put_long_nbr(d / 10)))
		ft_printf_put_char((d % 10) + 48);
	else
		ft_printf_put_char((d % 10) + 48);
	return (0);
}

static void		print_spaces(int l)
{
	if (ft_strchr(s_data.flags, '0') && !ft_strchr(s_data.flags, '-')
		&& s_data.precision == -1)
		s_data.precision = s_data.width;
	else if (s_data.precision < l)
		while (s_data.width-- > l)
			ft_printf_put_char(' ');
	else
		while (s_data.width-- > s_data.precision)
			ft_printf_put_char(' ');
}

static void		print_space_flag(void)
{
	if (ft_strchr(s_data.flags, ' ') && !ft_strchr(s_data.flags, '+')
		&& s_data.specifier != 'o' && --s_data.width
		&& srcrpl(s_data.flags, ' ', -1))
		ft_printf_put_char(' ');
}

void			print_all_digits(__int128 d)
{
	int			l;

	l = ft_len_nbr(d);
	if ((d < 0 || ft_strchr(s_data.flags, '+')) && s_data.specifier != 'o')
		--s_data.width;
	if (ft_strchr(s_data.flags, ' '))
		print_space_flag();
	if (!ft_strchr(s_data.flags, '-'))
		print_spaces(ft_len_nbr(d));
	if (d < 0 && (d = -d))
		ft_printf_put_char('-');
	else if (ft_strchr(s_data.flags, '+') && s_data.specifier != 'o')
		ft_printf_put_char('+');
	if (s_data.precision > l)
		while (s_data.precision > l++)
			ft_printf_put_char('0');
	else if (ft_strchr(s_data.flags, '#'))
		print_hesh();
	ft_put_long_nbr(d);
	if (ft_strchr(s_data.flags, '-'))
		print_spaces(ft_len_nbr(d));
}

void			print_digits(va_list ap)
{
	if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& !s_data.length)
		print_all_digits(va_arg(ap, int));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 1)
		print_all_digits(va_arg(ap, long));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 2)
		print_all_digits(va_arg(ap, long long));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 4)
		print_all_digits((short)va_arg(ap, int));
	else if ((s_data.specifier == 'd' || s_data.specifier == 'i')
			&& s_data.length == 5)
		print_all_digits((char)va_arg(ap, int));
}
