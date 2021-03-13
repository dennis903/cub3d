/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:26 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:49:27 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					calc_bmp_size()
{
	int				padding;
	int				size;

	padding = 4 - (((md.width * 3) % 4) % 4);
	size = md.height * (md.width * 3 + padding);
	return (size);
}