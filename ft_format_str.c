/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanelst <tvanelst@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:24:21 by tvanelst          #+#    #+#             */
/*   Updated: 2021/03/25 12:22:21 by tvanelst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_s(char *s, int size, int *data)
{
	char	*str;

	if (!s)
		s = "(null)";
	*(data + 2) = ft_strlen(s);
	if (size < 0 || (unsigned int)size > *(data + 2))
		size = *(data + 2);
	str = malloc(size + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, size + 1);
	return (str);
}

char	*ft_format_c(char c, int *data)
{
	char	*str;

	str = ft_calloc(2, 1);
	if (!str)
		return (0);
	*str = c;
	*(str + 1) = 0;
	*(data + 2) = 1;
	return (str);
}
