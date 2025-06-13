/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:57:19 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/13 11:26:11 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>

int	ft_isalpha(int c);												//--clean
int	ft_isdigit(int c);												//--clean
int	ft_isalnum(int c);												//--clean
int	ft_isascii(int c);												//--clean
int	ft_isprint(int c);												//--clean
size_t	ft_strlen(const char *str);									//--clean
void	*ft_memset(void *s, int c, size_t n);						//--TESTED CLEAN
void	ft_bzero(void *s, size_t n);								//--clean
void	*ft_memcpy(void *dest, const void *src, size_t n);			//--TESTED CLEAN
void	*ft_memmove(void *dest, const void *src, size_t n);			//--tba
size_t	ft_strlcpy(char *dst, const char *src, size_t size);		//--TESTED CLEAN
size_t	ft_strlcat(char *dst, const char *src, size_t size);		//--tba
int	ft_toupper(int c);												//--clean
int	ft_tolower(int c);												//--clean
char	*ft_strchr(const char *s, int c);							//--TESTED CLEAN
char	*ft_strrchr(const char *s, int c);							//--TESTED CLEAN
int	ft_strncmp(const char *s1, const char *s2, size_t n);			//--TESTED CLEAN
void	*memchr(const void *s, int c, size_t n);					//--tba
int	ft_memcmp(const void *s1, const void *s2, size_t n);			//--tba
char *ft_strnstr(const char *big, const char *little, size_t len);	//--tba
int	ft_atoi(const char *nptr);										//--tba

void	*calloc(size_t nmemb, size_t size);
char	*strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif