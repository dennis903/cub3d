/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:13:25 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/08 20:03:22 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp;
	unsigned const char	*s;

	temp = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- && *s != (unsigned char)c)
		*temp++ = *s++;
	if (*s == (unsigned char)c)
	{
		*temp = *s;
		dst = (void *)++temp;
		return (dst);
	}
	return (NULL);
}
