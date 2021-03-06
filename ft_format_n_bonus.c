/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_n_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanelst <tvanelst@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:31:51 by tvanelst          #+#    #+#             */
/*   Updated: 2021/04/14 13:34:48 by tvanelst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_n(va_list ap, t_converter *c)
{
	int		*my_n;
	char	**tab;
	int		i;

	my_n = va_arg(ap, int *);
	if (!my_n)
		return (0);
	i = 0;
	tab = (char *[]){"hh", "h", "l", "ll"};
	while (i < 4 && ft_strncmp(c->lenght_modifier, tab[i], 3))
		i++;
	if (i == 0)
		*(signed char *)my_n = c->counter;
	else if (i == 1)
		*(short int *)my_n = c->counter;
	else if (i == 2)
		*(long int *)my_n = c->counter;
	else if (i == 3)
		*(long long int *)my_n = c->counter;
	else
		*(int *)my_n = c->counter;
	return (0);
}
