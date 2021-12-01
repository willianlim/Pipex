/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:35 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 11:28:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

int	ft_child_process(t_pipex *chest, int *fd, int i)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(chest->path_exec[i - chest->j], \
	chest->cmd[i + 2], chest->envp) == -1)
		ft_message_clean(chest, 0, (i + 2 + chest->j));
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
	i += chest->j;
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
	if (execve(chest->path_exec[chest->argc - 4 - chest->j], \
	chest->cmd[chest->argc - 2], chest->envp) == -1)
		ft_message_clean(chest, 0, (chest->argc - 2));
	exit(EXIT_FAILURE);
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
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	chest;

	ft_memset(&chest, 0, sizeof(chest));
	ft_init_struct(&chest, argc, argv, envp);
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 9))
		{
			ft_here_doc(&chest);
			ft_parse_cmd(&chest);
			ft_pipeline_bonus(&chest);
		}
		else
		{
			ft_parse_cmd(&chest);
			ft_master(&chest);
		}
	}
	else
	{
		ft_putstr_fd(RED"Error: Bad argument\n"EOC, 1);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> file2\n", 1);
		ft_putstr_fd("    ./pipex here_doc <LIMITER> <cmd> <cmd1> \
		<...> file\n", 1);
	}
	return (0);
}
