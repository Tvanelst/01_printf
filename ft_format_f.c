/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanelst <tvanelst@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:44:19 by tvanelst          #+#    #+#             */
/*   Updated: 2021/04/04 17:02:38 by tvanelst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_n_size(char *s, int precision)
{
	int	size;

	size = ft_strlen(s);
	if (precision == -1)
		size += 7;
	else if (precision)
		size += precision + 1;
	return (size);
}

static char	*get_int_part(va_list ap, t_converter converter, int *int_size, int *size)
{
	va_list	ap2;
	char	*s_int;
	char	*s;

	va_copy(ap2, ap);
	s_int = ft_format_di(ap2, converter);
	va_end(ap2);
	if (!s_int)
		return (0);
	*size = get_n_size(s_int, converter.precision);
	s = malloc(*size + 1);
	if (!s)
		return (0);
	*int_size = ft_strlcpy(s, s_int, *size + 1);
	free(s_int);
	return (s);
}

char	*ft_format_f(va_list ap, t_converter converter)
{
	int		size;
	int		int_size;
	char	*s;
	double	n;

	s = get_int_part(ap, converter, &int_size, &size);
	if (!s)
		return (0);
	n = va_arg(ap, double);
	n = n - (int)n;
	if (converter.precision || ft_strchr(converter.flags, '#'))
		*(s + int_size++) = '.';
	while (int_size < size)
	{
		n *= 10;
		*(s + int_size++) = (int)n % 10 + '0';
	}
	/* if ((int)n % 5 && (n * 10) / 5 )
		//roundup */
	return (s);
}
