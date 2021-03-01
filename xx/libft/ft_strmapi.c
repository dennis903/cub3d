/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:33:57 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/12 14:33:57 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	if (s == NULL)
	{
		map = malloc(1);
		map[0] = '\0';
		return (map);
	}
	map = NULL;
	if (s && f)
	{
		if (!(map = (char *)malloc(sizeof(char) * (ft_strlen((char *)s)) + 1)))
			return (NULL);
		i = 0;
		while (i < (int)ft_strlen((char *)s))
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
