/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanelst <tvanelst@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:25:42 by thomasvanel       #+#    #+#             */
/*   Updated: 2021/04/10 11:39:22 by tvanelst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_char(char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

static char	*convert_arg_to_str(va_list ap, t_converter *c)
{
	t_tuple		*funptr;
	int			i;

	funptr = (t_tuple[]){{"s", &ft_format_s}, {"di", &ft_format_di},
	{"uxXp", &ft_format_uxp}, {"n", &ft_format_n}, {"f", &ft_format_f},
	{"c", &ft_format_c}};
	i = 0;
	while (!ft_strchr(funptr[i].str, c->convertion) && i < 5)
		i++;
	return (funptr[i].func(ap, c));
}

static void	ft_pad(t_converter c, char *s, int *counter, int len)
{
	if (!ft_strchr(c.flags, '-'))
	{
		if (s && c.pad == '0')
		{
			if (ft_strchr("-+ ", *s) && !ft_strchr("cs", c.convertion))
				ft_putchar_fd(*s++, 1);
			if (ft_strchr("pxX", c.convertion) && s[1] && ft_strchr("xX", s[1]))
			{
				ft_putchar_fd(*s++, 1);
				ft_putchar_fd(*s++, 1);
			}
		}
		while (c.width-- > len)
			output_char(c.pad, counter);
	}
	if (c.convertion == 'c' && s && !*s)
		ft_putchar_fd(*s, 1);
	else if (s)
		ft_putstr_fd(s, 1);
	while (c.width-- > len)
		output_char(c.pad, counter);
}

static void	display_value(va_list ap, const char **fmt, int *counter)
{
	char		*s;
	int			len;
	t_converter	c;

	c = create_converter(fmt, ap, *counter);
	if (ft_strchr("ge", c.convertion) || !c.convertion)
		return ;
	s = convert_arg_to_str(ap, &c);
	if (c.convertion == 'n')
		return ;
	len = 1;
	if (s && c.convertion != 'c')
		len = ft_strlen(s);
	ft_pad(c, s, counter, len);
	*counter += len;
	if (s)
		free(s);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			counter;

	va_start(ap, fmt);
	counter = 0;
	while (*fmt)
	{
		if (*fmt++ != '%')
			output_char(*(fmt - 1), &counter);
		else if (*fmt)
			display_value(ap, &fmt, &counter);
	}
	va_end(ap);
	return (counter);
}
