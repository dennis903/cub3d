/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:47:33 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/13 20:47:08 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*temp;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	if (begin != end)
		while (ft_strchr(set, s1[end]))
			end--;
	else
	{
		if (!(temp = (char *)malloc(1)))
			return (NULL);
		temp[0] = 0;
		return (temp);
	}
	if (!(temp = (char *)malloc(sizeof(char) * (end - begin + 2))))
		return (NULL);
	ft_strlcpy(temp, s1 + begin, end - begin + 2);
	return (temp);
}
