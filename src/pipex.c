/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:28:27 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/05 12:04:53 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	execute(char *cmd, char **env)
{
	
}

static	void	process(t_pipex *pipex, char *cmd1, char *cmd2, char **env)
{
	
}

void	ft_pipex(t_pipex *pipex, char **av, char **env)
{
	pipex->in_fd = ft_open_and_check(av[1], STDIN);
	pipex->out_fd = ft_open_and_check(av[4], STDOUT);
	dup2(pipex->in_fd, STDIN);
	dup2(pipex->out_fd, STDOUT);
}

