/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:12:44 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/29 08:09:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest && !src)
		return (0);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (num--)
		*cdest++ = *csrc++;
	return (dest);
}
