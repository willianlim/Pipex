/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:32:48 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 12:30:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

void	ft_message(t_pipex *chest)
{
	if (chest->argc < 6)
	{
		ft_putstr_fd(RED"Error: Bad argument\n"EOC, 1);
		ft_putstr_fd("Ex: ./pipex here_doc <LIMITER> <cmd> <cmd1> \
		<...> file\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	ft_here_doc(t_pipex *chest)
{
	int		infile;
	int		outfile;
	char	*s;

	chest->j = 1;
	ft_message(chest);
	unlink("here_doc.txt");
	outfile = open(chest->argv[chest->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0777);
	infile = open("here_doc.txt", O_WRONLY | O_CREAT, 0777);
	while (1)
	{
		s = get_next_line(0);
		if (!ft_strncmp(s, chest->argv[2], ft_strlen(chest->argv[2])))
		{
			free(s);
			close(infile);
			break ;
		}
		ft_putstr_fd(s, infile);
		free(s);
	}
	infile = open("here_doc.txt", O_RDONLY | O_CREAT, 0777);
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}
