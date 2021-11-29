/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:40 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/28 22:01:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

// Comment the waipid to pass the test

int	ft_child_process(t_pipex *chest, int *fd)
{
	int	infile;

	infile = open(chest->cmd[1][0], O_RDONLY, 0777);
	if (infile == -1)
		ft_error2(chest);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	if (execve(chest->path_exec[0], chest->cmd[2], chest->envp) == -1)
		ft_error(chest);
	exit(EXIT_FAILURE);
}

int	ft_parent_process(t_pipex *chest, int *fd)
{
	int	outfile;

	outfile = open(chest->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error2(chest);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (execve(chest->path_exec[1], chest->cmd[3], chest->envp) == -1)
		ft_error(chest);
	exit(EXIT_FAILURE);
}

int	ft_pipeline_mandatory(t_pipex *chest)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_error2(chest);
	pid1 = fork();
	if (pid1 == -1)
		ft_error2(chest);
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

	if (argc == 5)
	{
		ft_parse_cmd(&chest, argc, argv, envp);
		ft_pipeline_mandatory(&chest);
	}
	else
		write (STDOUT_FILENO, "command not found", 18);
	return (0);
}
