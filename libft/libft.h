/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:11:11 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/13 17:17:39 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

void	*ft_strrev(char *str, size_t size);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
char	*ft_strstr(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, const char *str, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
char	*ft_strstr(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strnew(size_t size);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strclr(char *s);
void	ft_strdel(char **as);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);

#endif
