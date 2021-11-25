/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_shared.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:18 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/25 00:57:55 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_SHARED_H
# define FT_PIPEX_SHARED_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_execute(char *argv, char *envp[]);
int		ft_error(void);
char	*ft_find_path(char *cmd, char *envp[]);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

#endif
