/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:40 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/25 00:56:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

static int	ft_child_process(char *argv[], char *envp[], int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error();
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	ft_execute(argv[2], envp);
	exit (EXIT_SUCCESS);
}

static int	ft_parent_process(char *argv[], char *envp[], int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	ft_execute(argv[3], envp);
	exit (EXIT_SUCCESS);
}

static int	ft_pipeline_mandatory(char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_error();
	if (pid1 == 0)
		ft_child_process(argv, envp, fd);
	else
	{
		waitpid(pid1, NULL, 0);
		ft_parent_process(argv, envp, fd);
	}
	exit (EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		ft_pipeline_mandatory(argv, envp);
	else
		write (STDOUT_FILENO, "deu ruim", 9);
	return (0);
}
