/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:23 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 11:57:05 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include "ft_pipex_shared.h"

/**
 * @brief This function creates the pipes, runs the fork and calls the parent
 * and child processes.
 *
 * @param chest Data struct.
 * @return int Exit status/code 0 on success or 2 on error.
 */
int		ft_pipeline_bonus(t_pipex *chest);

/**
 * @brief Reads the information being passed by the terminal through the
 * keyboard, stores it in a file that will be read in the pipeline.
 *
 * @param chest Data struct.
 */
void	ft_here_doc(t_pipex *chest);

#endif
