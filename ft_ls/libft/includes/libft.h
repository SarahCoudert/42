/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:11:11 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/10 21:21:46 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_strrev(char *str, size_t size);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				putn(void);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_putnbr(int nb);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memdup(const void *s, int len);

char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, const char *str, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				**char_sort(char **s, int count);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strclen(const char *s, int c);

size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst_db
{
	void			*content;
	size_t			content_size;
	struct s_lst_db	*next;
	struct s_lst_db	*prev;
}					t_lst_db;

void				del(void *content, size_t content_size);
void				tab_merge_sort(int *tab, int count);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstaddend(const void *ctt, size_t ctt_sz, t_list **lst);
void				ft_lstadd_db(t_lst_db **alstdb, t_lst_db *nw);
void				ft_lstdel_db(t_lst_db **alst, void (*del)(void*, size_t));
void				ft_lstdelone_db(t_lst_db **alt, void (*del)(void*, size_t));
void				delzero(void *ptr, size_t size);
void				ft_lstdelall_db(t_lst_db **alst);
void				ft_lstaddend_db(const void *con, size_t co_s, t_lst_db **p);

int					ft_lstcountelements(t_list *lst);
int					ft_lstcountbytes(t_list *lst);
int					ft_lstsumsize_db(t_lst_db *lst);
int					ft_lstlen(t_list *list);
int					ft_lstlen_db(t_lst_db *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

t_lst_db			*ft_lstgetend_db(t_lst_db **lst);
t_lst_db			*ft_lstgetstart_db(t_lst_db **lst);
t_lst_db			*ft_lstnew_db(void const *cont, size_t cont_size);
t_lst_db			*ft_lstgo_n_next(t_lst_db *lst, int n);
t_lst_db			*ft_lstgo_n_prev(t_lst_db *lst, int n);

char				*ft_strif(char *str, char *found);
char				*ft_lsttochar_db(t_lst_db **lst);

#endif
