/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:48:08 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 17:17:53 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_gets(char **args);

char	**ft_split(char const *s, char c);

int		ft_atoi(const char *nptr);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

#endif