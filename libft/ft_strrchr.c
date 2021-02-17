/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:37:16 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/11 15:37:16 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*s)
		s++;
	while (s != temp && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
