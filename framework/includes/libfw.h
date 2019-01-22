/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfw.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:55:45 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 18:18:05 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFW_H
# define LIBFW_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** LIBC's Functions
*/

void				fw_bzero(void *s, size_t n);
int					fw_isalpha(int c);
int					fw_isdigit(int c);
int					fw_isalnum(int c);
int					fw_isascii(int c);
int					fw_isprint(int c);
int					fw_toupper(int c);
int					fw_tolower(int c);
int					fw_atoi(const char *str);
int					fw_strcmp(const char *s1, const char *s2);
int					fw_strncmp(const char *s1, const char *s2, size_t n);
int					fw_memcmp(const void *s1, const void *s2, size_t n);
size_t				fw_strlen(const char *s);
size_t				fw_strlcat(char *dst, const char *src, size_t size);
void				*fw_memset(void	*b, int c, size_t len);
void				*fw_memcpy(void *dst, const void *src, size_t n);
void				*fw_memccpy(void *dst, const void *src, int c, size_t n);
void				*fw_memmove(void *dst, const void *src, size_t len);
void				*fw_memchr(const void *s, int c, size_t n);
char				*fw_strstr(const char *haystack, const char *needle);
char				*fw_strcat(char *s1, const char *s2);
char				*fw_strncat(char *s1, const char *s2, size_t n);
char				*fw_strcpy(char *dst, const char *src);
char				*fw_strncpy(char *dst, const char *src, size_t len);
char				*fw_strdup(const char *s1);
char				*fw_strnstr(const char *haystack, const char *neddle,
		size_t len);
char				*fw_strchr(const char *s, int c);
char				*fw_strrchr(const char *s, int c);

/*
** Additional Functions
*/

void				fw_memdel(void **ap);
void				fw_strdel(char **as);
void				fw_strclr(char *s);
void				fw_striter(char *s, void (*f)(char *));
void				fw_striteri(char *s, void (*f)(unsigned int, char *));
void				fw_putchar(char c);
void				fw_putstr(char const *s);
void				fw_putendl(char const *s);
void				fw_putnbr(int n);
void				fw_putchar_fd(char c, int fd);
void				fw_putstr_fd(char const *s, int fd);
void				fw_putendl_fd(char const *s, int fd);
void				fw_putnbr_fd(int n, int fd);
int					fw_strequ(char const *s1, char const *s2);
int					fw_strnequ(char const *s1, char const *s2, size_t n);
void				*fw_memalloc(size_t size);
char				*fw_strnew(size_t size);
char				*fw_strmap(char const *s, char (*f)(char));
char				*fw_strmapi(char const *s, char (*f)(unsigned int, char));
char				*fw_strsub(char const *s, unsigned int start, size_t len);
char				*fw_strjoin(char const *s1, char const *s2);
char				*fw_strtrim(char const *s);
char				*fw_itoa(int n);
char				**fw_strsplit(char const *s, char c);

/*
** List Manipulation Functions and their Structure
*/

typedef struct		s_mylist
{
	void			*content;
	size_t			content_size;
	struct s_mylist	*next;
}					t_mylist;

void				fw_lstdelone(t_mylist **alst, void (*del)(void *, size_t));
void				fw_lstdel(t_mylist **alst, void (*del)(void *, size_t));
void				fw_lstadd(t_mylist **alst, t_mylist *new);
void				fw_lstiter(t_mylist *lst, void (*f)(t_mylist *elem));
t_mylist			*fw_lstnew(void const *content, size_t content_size);
t_mylist			*fw_lstmap(t_mylist *lst, t_mylist *(*f)(t_mylist *elem));

/*
** Other Functions
*/

void				fw_print_tables(char **tab);
int					fw_str_is_alpha(char *s);
int					fw_str_is_numeric(char *s);
int					fw_str_is_printable(char *s);
int					fw_str_is_lowercase(char *s);
int					fw_str_is_uppercase(char *s);
int					fw_isprime(size_t n);

#endif
