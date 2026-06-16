/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:41:11 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 21:19:06 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned long nb, char c);
int	ft_putptr(void *ptr);

#endif