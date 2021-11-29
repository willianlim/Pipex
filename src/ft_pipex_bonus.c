/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:35 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/29 08:47:54 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

static int	ft_child_process(t_pipex *chest, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(chest->path_exec[0], chest->cmd[2], chest->envp) == -1)
		ft_message_clean(chest, 0, 2);
	if (execve(chest->path_exec[chest->i], \
	chest->cmd[(chest->i + 2)], chest->envp) == -1)
		ft_message_clean(chest, 0, (chest->i + 2));
	exit(EXIT_FAILURE);
}

static void	ft_parent_process(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static int	ft_pipeline_bonus(t_pipex *chest)
{
	int		fd[2];
	pid_t	pid;

	chest->i = -1;
	while (++chest->i < (chest->argc - 3))
	{
		if (pipe(fd) == -1)
			ft_message_clean(chest, 2, 0);
		pid = fork();
		if (pid == -1)
			ft_message_clean(chest, 2, 0);
		else if (!pid)
			ft_child_process(chest, fd);
		else
			ft_parent_process(fd, pid);
	}
	exit(EXIT_SUCCESS);
}

static int	ft_master(t_pipex *chest)
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
	ft_pipeline_bonus(chest);
	dup2(outfile, STDOUT_FILENO);
	close (outfile);
	if (execve(chest->path_exec[chest->argc - 4], \
	chest->cmd[chest->argc - 2], chest->envp) == -1)
		ft_message_clean(chest, 0, (chest->argc - 2));
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
