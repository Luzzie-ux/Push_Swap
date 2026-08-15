/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:41:11 by diferrei          #+#    #+#             */
/*   Updated: 2026/06/14 21:19:06 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_fprintf(int fd, const char *format, ...);
int	ft_fputnbr(int fd, int n);
int	ft_fputnbr_unsigned(int fd, unsigned int nb);
int	ft_fputchar(int fd, char c);
int	ft_fputstr(int fd, char *s);
int	ft_fputnbr_hex(int fd, unsigned long nb, char c);
int	ft_fputptr(int fd, void *ptr);

#endif