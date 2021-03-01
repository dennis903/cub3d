/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:59:58 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/18 15:18:03 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
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
