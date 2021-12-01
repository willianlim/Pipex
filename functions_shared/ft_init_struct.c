/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:51:31 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/30 13:51:48 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

void	ft_init_struct(t_pipex *chest, int argc, char *argv[], char *envp[])
{
	chest->argc = argc;
	chest->argv = argv;
	chest->envp = envp;
}
