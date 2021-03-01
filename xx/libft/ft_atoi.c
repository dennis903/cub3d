/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:10:53 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/15 17:15:06 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LLONG_MAX 9223372036854775807

int						check_over_range(unsigned long long sum, int sign)
{
	if (sum > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	return (sum * sign);
}

int						is_in(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else if (c >= 127)
		return (1);
	return (0);
}

int						ft_atoi(const char *str)
{
	int					minus;
	unsigned long long	result;

	result = 0;
	minus = 1;
	while (is_in(*str))
		str++;
	if (*str == '-')
	{
		minus *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	return (check_over_range(result, minus));
}
