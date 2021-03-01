/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:34:57 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/11 14:34:57 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_correct(const char *hay, const char *ned, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (i < len && ned[j])
	{
		if (hay[i] != ned[j])
			return (0);
		i++;
		j++;
	}
	if (ned[j] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
			if (is_correct(haystack, needle, i, len))
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
