/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanelst <tvanelst@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:24:21 by tvanelst          #+#    #+#             */
/*   Updated: 2021/04/09 21:34:19 by tvanelst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_s(va_list ap, t_converter *c)
{
	char	*s;
	int		size;
	char	*input;

	input = va_arg(ap, char *);
	if (!input)
		input = "(null)";
	size = ft_strlen(input);
	if (0 <= c->precision && c->precision < size)
		size = c->precision;
	s = malloc(size + 1);
	if (!s)
		return (0);
	ft_strlcpy(s, input, size + 1);
	return (s);
}