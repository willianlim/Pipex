/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 11:45:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_STRUCT_H
# define FT_PIPEX_STRUCT_H

# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define EOC "\033[0;0m"

# define SPACE ' '
# define COLON ':'
# define PATH "PATH"
# define FRONT_SLASH "/"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	***cmd;
	char	**paths;
	char	*path;
	char	*path_slash;
	char	**path_exec;
	int		i;
	int		j;
}t_pipex;

#endif
