/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:56:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/28 21:31:53 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"
#include <stdio.h>

void	*ft_find_path(t_pipex *chest, int k)
{
	int	i;

	i = -1;
	while (!ft_strnstr(chest->envp[++i], PATH, 4))
		;
	chest->paths = ft_split(chest->envp[i], COLON);
	i = -1;
	while (chest->paths[++i])
	{
		chest->path_slash = ft_strjoin(chest->paths[i], FRONT_SLASH);
		free(chest->paths[i]);
		chest->path = ft_strjoin(chest->path_slash, chest->cmd[k][0]);
		free(chest->path_slash);
		if (!access(chest->path, F_OK | X_OK))
		{
			while (chest->paths[++i])
				free(chest->paths[i]);
			free(chest->paths);
			return (chest->path);
		}
		free(chest->path);
	}
	free(chest->paths);
	return (0);
}

void	ft_init_struct(t_pipex *chest, int argc, char *argv[], char *envp[])
{
	chest->argc = argc;
	chest->argv = argv;
	chest->envp = envp;
}

int	ft_parse_cmd(t_pipex *chest, int argc, char *argv[], char *envp[])
{
	int		j;
	int		i;

	i = 1;
	j = -1;
	ft_init_struct(chest, argc, argv, envp);
	chest->path_exec = (char **)calloc(sizeof(char *), (argc - 2));
	chest->cmd = (char ***)calloc(sizeof(char **), (chest->argc + 1));
	i = -1;
	while (chest->argv[++j] != NULL)
		chest->cmd[j] = ft_split(chest->argv[j], SPACE);
	j = -1;
	i = 0;
	while (++i <= (chest->argc - 3))
	{
		chest->path_exec[++j] = ft_find_path(chest, (i + 1));
		if (chest->path_exec[j] == NULL)
			ft_error2(chest);
	}
	return (0);
}
