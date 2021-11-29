/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:05:16 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/28 21:59:49 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

int	ft_error(t_pipex *chest)
{
	int	i;
	int	j;

	i = -1;
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free(chest->path);
	while (chest->cmd[++i])
	{
		j = -1;
		while (chest->cmd[i][++j])
			free(chest->cmd[i][j]);
		free(chest->cmd[i]);
	}
	free(chest->cmd);
	i = -1;
	while (chest->path_exec[++i])
		free(chest->path_exec[i]);
	free(chest->path_exec);
	exit(127);
}

int	ft_error2(t_pipex *chest)
{
	int	i;
	int	j;

	i = -1;
	while (chest->cmd[++i])
	{
		j = -1;
		while (chest->cmd[i][++j])
			free(chest->cmd[i][j]);
		free(chest->cmd[i]);
	}
	free(chest->cmd);
	i = -1;
	while (chest->path_exec[++i])
		free(chest->path_exec[i]);
	free(chest->path_exec);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(errno);
}
