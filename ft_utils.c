/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albezerr <albezerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:42:42 by albezerr          #+#    #+#             */
/*   Updated: 2024/12/22 14:42:42 by albezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		len += write(1, s++, 1);
	}
	return (len);
}

int	ft_print_nbr(long nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_print_nbr(nbr / 10);
		count += ft_print_nbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		count += ft_putchar(c);
	}
	return (count);
}
