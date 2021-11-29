/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:40 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/29 09:45:16 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

// Comment the waipid (line 65) to pass the PIPEX TESTER by vfurmane

static int	ft_child_process(t_pipex *chest, int *fd)
{
	int	infile;

	infile = open(chest->cmd[1][0], O_RDONLY, 0777);
	if (infile == -1)
		ft_message_clean(chest, 2, 0);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	if (execve(chest->path_exec[0], chest->cmd[2], chest->envp) == -1)
		ft_message_clean(chest, 0, 2);
	exit(EXIT_FAILURE);
}

static int	ft_parent_process(t_pipex *chest, int *fd)
{
	int	outfile;

	outfile = open(chest->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_message_clean(chest, 2, 0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (execve(chest->path_exec[1], chest->cmd[3], chest->envp) == -1)
		ft_message_clean(chest, 0, 3);
	exit(EXIT_FAILURE);
}

static int	ft_pipeline_mandatory(t_pipex *chest)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_message_clean(chest, 2, 0);
	pid1 = fork();
	if (pid1 == -1)
		ft_message_clean(chest, 2, 0);
	if (pid1 == 0)
		ft_child_process(chest, fd);
	else
	{
		waitpid(pid1, NULL, 0);
		ft_parent_process(chest, fd);
	}
	exit (EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	chest;

	ft_memset(&chest, 0, sizeof(chest));
	if (argc == 5)
	{
		ft_parse_cmd(&chest, argc, argv, envp);
		ft_pipeline_mandatory(&chest);
	}
	else
		write (STDOUT_FILENO, "command not found", 18);
	return (0);
}
