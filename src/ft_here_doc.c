/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:32:48 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 10:56:05 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_bonus.h"

void	ft_here_doc(t_pipex *chest)
{
	int		infile;
	int		outfile;
	char	*s;

	chest->j = 1;
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
