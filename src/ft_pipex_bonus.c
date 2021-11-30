/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:35 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/30 07:34:27 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

int	ft_child_process(t_pipex *chest, int *fd, int i)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(chest->path_exec[i], \
	chest->cmd[i + 2], chest->envp) == -1)
		ft_message_clean(chest, 0, (i + 2));
	exit(EXIT_FAILURE);
}

void	ft_parent_process(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

int	ft_pipeline_bonus(t_pipex *chest)
{
	int		i;
	int		fd[2];
	pid_t	pid;

	i = -1;
	while (++i < (chest->argc - 4))
	{
		if (pipe(fd) == -1)
			ft_message_clean(chest, 2, 0);
		pid = fork();
		if (pid == -1)
			ft_message_clean(chest, 2, 0);
		if (!pid)
			ft_child_process(chest, fd, i);
		else
			ft_parent_process(fd, pid);
	}
	if (execve(chest->path_exec[chest->argc - 4], \
	chest->cmd[chest->argc - 2], chest->envp) == -1)
		ft_message_clean(chest, 0, (chest->argc - 2));
	exit(EXIT_SUCCESS);
}

int	ft_master(t_pipex *chest)
{
	int	outfile;
	int	infile;

	outfile = open(chest->argv[chest->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0777);
	infile = open(chest->argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_message_clean(chest, 2, 0);
	dup2(infile, STDIN_FILENO);
	close (infile);
	dup2(outfile, STDOUT_FILENO);
	close (outfile);
	ft_pipeline_bonus(chest);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	chest;

	ft_memset(&chest, 0, sizeof(chest));
	if (argc >= 5)
	{
		ft_parse_cmd(&chest, argc, argv, envp);
		ft_master(&chest);
	}
	else
		write (STDOUT_FILENO, "command not found", 18);
	return (0);
}
