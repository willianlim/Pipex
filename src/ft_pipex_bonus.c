/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:35 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/25 00:56:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

static void	ft_child_process(char *argv[], char *envp[], int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[2], envp);
}

static void	ft_parent_process(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static void	ft_pipeline_bonus(char *argv[], char *envp[], int argc)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = -1;
	while (++i < (argc - 3))
	{
		if (!(i % 2))
		{
			if (pipe(fd) < 0)
				exit(1);
		}
		if (i % 2)
		{
			if (pipe(fd) < 0)
				exit(1);
		}
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (!pid)
			ft_child_process(argv, envp, fd);
		else
			ft_parent_process(fd, pid);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	outfile;
	int	infile;

	if (argc >= 5)
	{
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		infile = open(argv[1], O_RDONLY, 0777);
		dup2(infile, STDIN_FILENO);
		ft_pipeline_bonus(argv, envp, argc);
		dup2(outfile, STDOUT_FILENO);
		ft_execute(argv[argc - 2], envp);
	}
	else
		write (STDOUT_FILENO, "deu ruim", 9);
	return (0);
}
