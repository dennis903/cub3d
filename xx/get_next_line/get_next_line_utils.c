/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:06:27 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/23 18:22:32 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strndup(const char *s1, int n)
{
	char	*temp;
	int		i;

	i = 0;
	if (ft_strlen(s1) == 0)
	{
		if (!(temp = malloc(1)))
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (!(temp = (char *)malloc(n + 1)))
		return (NULL);
	while (i < n)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		idx;
	int		s2_idx;

	if (!(s1 && s2))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx++;
	}
	s2_idx = 0;
	while (s2[s2_idx])
		str[idx++] = s2[s2_idx++];
	str[idx] = '\0';
	return (str);
}

char		*ft_strdup(const char *s1)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		if (!(temp = malloc(1)))
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	len = ft_strlen(s1);
	if (!(temp = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
