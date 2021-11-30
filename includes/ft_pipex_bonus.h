/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:23 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/30 06:55:34 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "ft_pipex_shared.h"

/**
 * @brief This function creates the pipes, runs the fork and calls the parent
 * and child processes.
 *
 * @param chest Data struct.
 * @return int Exit status/code 0 on success or 2 on error.
 */
static int	ft_pipeline_bonus(t_pipex *chest);

#endif
