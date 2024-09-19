/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:44:06 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/19 19:00:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h> // REMOVE AFTER DONE ERROR HANDLING

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*alloc_word(const char *start, int len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	// printf("WORD: %s\n", word ); // REMOVE AFTER DONE ERROR HANDLING
	return (word);
}

static void	*ft_freeresult(char **result, size_t w_i)
{
	while (w_i > 0)
		free (result[--w_i]);
	free (result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	const char	*w_start;
	size_t		w_i;

	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	w_i = 0;
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		w_start = s;
		while (*s && *s != c)
			s++;
		if (s > w_start)
		{
			result[w_i] = alloc_word(w_start, s - w_start);
			if (!result[w_i])
				return (ft_freeresult(result, w_i));
			w_i++;
		}
	}
	result[w_i] = NULL;
	return (result);
}
