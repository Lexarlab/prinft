/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albezerr <albezerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:15:27 by albezerr          #+#    #+#             */
/*   Updated: 2024/12/22 15:15:27 by albezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_handle_conversion(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_print_nbr(long nbr);
int		ft_put_unsigned(unsigned int nbr);
int		ft_puthex(unsigned int n, int is_upper);
int		ft_putptr(void *ptr);

#endif