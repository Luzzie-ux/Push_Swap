/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:22:04 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/08 18:36:03 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//prototipos
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long nbr);
int		ft_putptr(void *ptr);
int		ft_putnbr_un(unsigned int nbr);
int		ft_puthex(unsigned int nbr, char format);
int		ft_printf(const char *format, ...);

#endif