/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:56:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/25 01:00:07 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

char	*ft_find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	char	*path_slash;
	int		i;

	i = -1;
	while (!ft_strnstr(envp[++i], "PATH", 4))
		;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path_slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (!access(path, F_OK))
			return (path);
	}
	return (0);
}

void	ft_execute(char *argv, char *envp[])
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(ft_find_path(cmd[0], envp), cmd, envp) == -1)
		ft_error();
}
