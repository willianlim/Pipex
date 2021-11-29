/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:11:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/27 22:11:21 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_STRUCT_H
# define FT_PIPEX_STRUCT_H

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
}t_pipex;

#endif
