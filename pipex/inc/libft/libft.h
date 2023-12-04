/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:59:33 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/28 10:44:01 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;
int		ft_isalpha(int str);
int		ft_isalnum(int c);
int		ft_toupper(int str);
int		ft_tolower(int chr);
int		ft_isdigit(int str);
int		ft_isascii(int str);
int		ft_isprint(int str);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t b);
void	*ft_memmove(void *destination, const void *source, size_t b);
void	*ft_memchr(const void *str, int chr, size_t b);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_realloc(void *ptr, size_t original_size, size_t new_size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *source, size_t	size_of_str);
int		ft_strncmp(const char *sn1, const char *sn2, size_t nb);
int		ft_memcmp(const void *sn1, const void *sn2, size_t nb);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
