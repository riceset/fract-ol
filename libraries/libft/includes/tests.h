/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:53:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/27 05:36:56 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "colors.h"
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ASCII_MIN 0
# define ASCII_MAX 127

static void	test_is(int (*is)(int));
static void	test_strlen(char *s);
static void	test_memset(void *s, int c, size_t len);
static void	test_bzero(void *b, size_t len);
static void	test_memcpy(const void *src, size_t n);
static void	test_memmove(const void *src, size_t n);
static void	test_memcpy_memmove(void *(*f)(void *, const void *, size_t),
				const void *src, size_t n);
static void	test_strlcpy(char *src, size_t cpysize);
static void	test_strlcat(char *dst, const char *src, size_t f_dst_s);
static void	test_to_upper_lower(int (*f)(int c), int c);
static void	test_strchr_strrchr(char *(*f)(const char *, int), const char *s,
				int c);
static void	h_reset_memcpy_memmove(char **or, char **ft);
static void	print_w_nul_nonprnt(char *title, char *s, size_t n);
static void	test_strncmp_memcmp(int (*f)(const void *, const void *, size_t),
				const char *s1,
				const char *s2,
				size_t n);
static void	test_memchr(const void *s, int c, size_t n);
static void	test_strnstr(const char *str, const char *substr, size_t len);
static void	test_atoi(const char *str);
static void	test_atoi_inputs(void);
static void	test_substr(char const *s, unsigned int start, size_t len);
static void	test_strjoin(char const *s1, char const *s2);
static void	test_strtrim(char const *s1, char const *set);
static void	test_split(char const *s, char c);
static void	test_itoa(int n);
static void	test_striteri(char *s);
static void	test_strmapi(char const *s);
static char	byval_rev_case(unsigned int i, char c);
static void	byrefer_rev_case(unsigned int i, char *c);
static void	test_putchar_fd(char c);
static void	test_putstr_endl(void (*f)(char *, int), char *s);
static void	test_putnbr(int n);
static void	test_lstnew(char *content);
static void	test_lstadd_front_back(void);
static void	test_lstsize(void);
static void	test_lstlast(void);
static void	test_lstdelone(void);
static void	test_lstclear(void);
static void	test_lstiter(void);
static void	test_lstmap(void);

#endif
