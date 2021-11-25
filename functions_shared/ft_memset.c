/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:56:33 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/24 20:56:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = ((char *)s);
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
