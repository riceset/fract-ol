/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:16:58 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/26 23:49:51 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef enum e_status
{
	IN,
	OUT
}				t_status;

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	dup = malloc(n + 1);
	if (dup)
		ft_strlcpy(dup, s1, n + 1);
	return (dup);
}

static size_t	str_count(char const *s, char c)
{
	size_t		sc;
	t_status	state;

	s--;
	sc = 0;
	state = OUT;
	while (*++s)
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			sc++;
		}
	}
	return (sc);
}

static size_t	count_curr_str_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**helper(char **ss, const char *s, size_t sc, const char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	while (++j < sc)
	{
		while (s[i] == c)
			i++;
		len = count_curr_str_size(s + i, c);
		ss[j] = ft_strndup(s + i, len);
		if (ss[j] == NULL)
		{
			while (j--)
				free(ss[j]);
			free(ss);
			return (NULL);
		}
		i += len;
	}
	ss[j] = NULL;
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	size_t	sc;

	if (s)
	{
		sc = str_count(s, c);
		ss = ft_calloc(sc + 1, sizeof(char *));
		if (ss)
			return (helper(ss, s, sc, c));
	}
	return (NULL);
}
