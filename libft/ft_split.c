/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:41:30 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/14 23:25:01 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			countwords(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int			get_length(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	free_mem(char **split, int idx)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		free(split[i]);
		i++;
	}
}

static char	**fillsplit(char **split, char const *s, char c, int words)
{
	int		split_idx;
	int		j;
	int		words_len;

	split_idx = -1;
	j = 0;
	while (++split_idx < words)
	{
		while (*s == c)
			s++;
		words_len = get_length(s, c);
		if (!(split[split_idx] = malloc(sizeof(char *) * (words_len + 1))))
			free_mem(split, split_idx);
		j = 0;
		while (j < words_len)
		{
			split[split_idx][j] = *s++;
			j++;
		}
		split[split_idx][j] = '\0';
	}
	split[split_idx] = 0;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	split = fillsplit(split, s, c, words);
	return (split);
}
