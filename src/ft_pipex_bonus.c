/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:35 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/27 22:14:44 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

int	ft_child_process(t_pipex *chest, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(ft_find_path(chest, (chest->i + 2)), \
	chest->cmd[(chest->i + 2)], chest->envp) == -1)
		ft_error(chest);
	exit(EXIT_FAILURE);
}

void	ft_parent_process(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

void	ft_pipeline_bonus(t_pipex *chest)
{
	int		fd[2];
	pid_t	pid;

	chest->i = -1;
	while (++chest->i < (chest->argc - 3))
	{
		if (pipe(fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (!pid)
			ft_child_process(chest, fd);
		else
			ft_parent_process(fd, pid);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	chest;
	int		outfile;
	int		infile;

	ft_memset(&chest, 0, sizeof(chest));
	if (argc >= 5)
	{
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		infile = open(argv[1], O_RDONLY, 0777);
		ft_parse_cmd(&chest, argc, argv, envp);
		dup2(infile, STDIN_FILENO);
		close (infile);
		ft_pipeline_bonus(&chest);
		dup2(outfile, STDOUT_FILENO);
		close (outfile);
		if (execve(ft_find_path(&chest, argc - 2), \
		chest.cmd[argc - 2], chest.envp) == -1)
			ft_error(&chest);
	}
	else
		write (STDOUT_FILENO, "deu ruim", 9);
	return (0);
}
