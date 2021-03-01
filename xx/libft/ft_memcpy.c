/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:46:37 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/04 20:01:35 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*temp;
	unsigned const char		*s;
	size_t					i;

	temp = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*((char *)temp + i) = *((char *)s + i);
		i++;
	}
	return (dst);
}
