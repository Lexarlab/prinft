/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_partii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albezerr <albezerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:46:49 by albezerr          #+#    #+#             */
/*   Updated: 2024/12/22 16:33:36 by albezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int nbr)
{
	int		count;
	char	c;

	count = 0;
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

int	ft_puthex(unsigned int n, int is_upper)
{
	int		count;
	char	*base;

	count = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n / 16)
		count += ft_puthex(n / 16, is_upper);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	char			buffer[18];
	int				len;
	char			*base;
	int				i;

	len = 0;
	i = 17;
	base = "0123456789abcdef";
	buffer[17] = '\0';
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	while (addr)
	{
		buffer[i--] = base[addr % 16];
		addr /= 16;
	}
	len += write(1, "0x", 2);
	len += write(1, &buffer[i + 1], 17 - i);
	return (len);
}
