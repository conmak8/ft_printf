/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:26:47 by cmakario          #+#    #+#             */
/*   Updated: 2023/11/17 14:42:34 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0')
	{
		if (ft_print_char((int) *str) == -1)
			return (-1);
		++count;
		++str;
	}
	return (count);
}

int	ft_printf_options(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_p(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_digit(va_arg(args, int), 10, 0));
	else if (specifier == 'u')
		return (ft_print_digit(va_arg(args, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (ft_print_digit(va_arg(args, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (ft_print_digit(va_arg(args, unsigned int), 16, 1));
	else
		return (ft_print_char('%'));
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	va_start(args, string);
	count = 0;
	while (*string != '\0')
	{
		if (*string == '%')
			tmp = ft_printf_options(*(++string), args);
		else
			tmp = write(1, string, 1);
		if (tmp == -1)
			return (-1);
		count += tmp;
		++string;
	}
	va_end(args);
	return (count);
}
