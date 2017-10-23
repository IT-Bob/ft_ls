/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:51:57 by aguerin           #+#    #+#             */
/*   Updated: 2017/08/24 09:01:34 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
unsigned long	ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
int				ft_putchar(char c);
int				ft_putstr(char const *str);
int				ft_putendl(char const *s);
int				ft_putnbr(int n);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putendl_fd(char const *s, int fd);
int				ft_putnbr_fd(int n, int fd);

/*
** \struct s_list
** \brief	Structure pour les listes de libft
**
** \param	content			- Variable pour le stockage d'une valeur
** \param	content_size	- Taille de la Variable
** \param	next			- Pointeur sur le maillon suivant
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_nbrlen(long nb);
int				ft_isspace(int c);
void			ft_swap(char *a, char *b);
int				ft_putnbrl(int n);
int				ft_putnbrs(int n);
int				ft_putcharl(char c);
int				ft_putchars(char c);
int				ft_putstrs(char const *str);
int				ft_factorial(int nb);
int				ft_sqrt(int nb);
int				ft_count_word(char const *str, char c);
t_list			*ft_lstdelonejoin(int content_size, t_list *list);
char			*ft_strfreejoin(char *s1, char *s2);
void			ft_lstaddend(t_list **alst, t_list *new);
t_list			*ft_lstaddnew(void const *content, size_t content_size,
								t_list *list);
t_list			*ft_lstaddalpha(t_list **alst, t_list *new);
void			ft_lstiter_reverse(t_list *lst, void (*f)(t_list *elem));
void			fill_tab(int tab[], unsigned int size, int value);
int				ft_putcharl_fd(char c, int fd);

char			*ft_itoa_base(unsigned long nb, int base);
int				ft_putnbr_long(long long int n);
char			*ft_itoa_long(long long n);
int				ft_atoi_base(const char *str, int base);
long long int	ft_pow(int nb, unsigned int pow);
int				ft_putwchar(long c);
int				ft_putwstr(wchar_t *str);
int				ft_islowercase(char	c);
int				ft_isuppercase(char c);
int				ft_putwcharl(long c);
int				ft_putwchars(long c);
int				ft_putwendl(wchar_t *str);
int				ft_putwstrs(wchar_t *str);
int				ft_putnstr(const char *str, unsigned int n);
int				ft_putnstrs(const char *str, unsigned int n);
int				ft_putwnchar(wchar_t *str, unsigned int n);
int				ft_putstrupper(const char *str);
int				ft_putstrlower(const char *str);
unsigned long	ft_strwlen(wchar_t *str);
int				ft_putxchar(char c, int x);
int				ft_putxwchar(wchar_t c, int x);
int				ft_strwbytlen(wchar_t *str);
int				ft_charwbytlen(wchar_t c);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
int				ft_is_valid_char(char *valid, char c);

void			ft_perror(const char *message, const int value);

void			ft_strdeldouble(char **str);
#endif
