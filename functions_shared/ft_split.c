/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:57:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/24 20:57:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

static size_t	count_word(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	*break_point;
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	ret = (char **)ft_calloc(sizeof(char *), (count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			break_point = (char *)s;
			while (*s && *s != c)
				s++;
			ret[i] = (char *)malloc((len = s - break_point + 1) * sizeof(char));
			ft_strlcpy(ret[i++], break_point, len);
		}
		else
			s++;
	}
	return (ret);
}
