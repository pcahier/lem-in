/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrossma <agrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:03 by agrossma          #+#    #+#             */
/*   Updated: 2018/12/06 10:53:44 by agrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Include headers for the typedefs, macros and standard functions
** stdlib.h for the functions malloc(3) and free(3)
** string.h for the macro NULL and the typedef size_t
** unistd.h for the function write(2)
** ft_printf.h for ft_printf and more
*/
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf.h"

# define NULL_CHECK(x) if (x == NULL) return (NULL)
# define VOID_NULL_CHECK(x) if (x == NULL) return
# define MALLOC_CHECK(x) if (x == NULL) return (NULL)
# define GNL_CHECK(x) if (!x && (x = ft_strnew(1)) == NULL) return (-1)
# define BUFF_SIZE 32

extern char		*g_optarg;
extern int		g_optind;
extern int		g_optopt;
extern int		g_opterr;
extern int		g_optreset;

/*
** Struct for a linked list
** \member content The data contained inside the link
** \member content_size The size of the data contained in the link
** \member next The adress of the next link or NULL if it's the last
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char	*buf;
	int		count;
	int		i;
	int		nl;
	int		fd;
}				t_gnl;

/*
** Typedef for the memory related functions
*/
typedef unsigned char	t_byte;
typedef int				t_bool;
/*
** Functions already existing in the libc, rewrited for this library
** \see man function (without the ft_)
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_abs(int i);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, size_t maxlen);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
char			*ft_index(const char *s, int c);
int				ft_getopt(int argc, const char **argv, const char *optstring);
void			*ft_memmem(const void *big, size_t big_len,
				const void *little, size_t little_len);
void			*ft_memcalloc(size_t count, size_t size);

/*
** Functions missing from the libc or present in a different way
** TODO: add heap sort and merge sort (for integer array)
*/
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplitspace(char const *s);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_extcmp(const char *path, const char *ext);
int				get_next_line(const int fd, char **line);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memrealloc(void *ptr, size_t new_size, size_t old_size);
size_t			ft_memsize(void *ptr);
void			ft_memdel(void **ap);
void			ft_memdel2d(void **array);
void			ft_putaddr(void *ptr);
void			ft_putaddr_fd(void *ptr, int fd);
void			ft_putchar(char c);
int				ft_iputchar(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_atoi_base(const char *str, int base);
size_t			ft_2darraylen(void **array);
int				ft_isnumber(const char *str);
char			*ft_insert(char *s1, const char *s2, size_t pos);
char			*ft_strmerge(char *a, char *b);

/*
** Functions to manipulate a linked list
*/
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
