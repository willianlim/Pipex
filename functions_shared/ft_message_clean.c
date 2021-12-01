/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:05:16 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 18:04:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

static void	ft_message(t_pipex *chest, int t_bool, int k)
{
	if (!t_bool)
	{
		ft_putstr_fd(chest->cmd[k][0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free(chest->path);
	}
	else if (t_bool == 1)
	{
		ft_putstr_fd(chest->cmd[k][0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (t_bool == 2)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
}

int	ft_message_clean(t_pipex *chest, int t_bool, int k)
{
	int	i;
	int	j;
	int	w;

	i = -1;
	w = 1;
	ft_message(chest, t_bool, k);
	if (chest->argc - 2 == k)
		w = 127;
	else if (k >= 2 && k <= chest->argc - 3)
		w = 0;
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
	exit(w);
}
