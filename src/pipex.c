/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:28:27 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/12 20:22:13 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	child_process(t_pipex *pipex, char *cmd)
{
	dup2(pipex->end[0], STDIN);
	close(pipex->end[1]);
}

static	int	ft_open_and_check(char *file, int mode)
{
	int	fd;

	if (mode == STDOUT)
	{
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ft_error_exit(NULL, NULL, "Error open");
	}
	else if (mode == STDIN)
	{
		if (access(file, F_OK) == -1)
			ft_error_exit(NULL, NULL, "Error, No such file or directory\n");
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error_exit(NULL, NULL, "Error open");
	}
	return (fd);
}

void	ft_pipex(t_pipex *pipex, char **av, char **env)
{
	pipex->in_fd = ft_open_and_check(av[1], STDIN);
	pipex->out_fd = ft_open_and_check(av[4], STDOUT);
	dup2(pipex->in_fd, STDIN);
	dup2(pipex->out_fd, STDOUT);
	if (pipe(pipex->end) == -1)
		ft_error_exit(NULL, NULL, "Error pipe.");
	pipex->parent = fork();
	if (pipex->parent == -1)
		ft_error_exit(NULL, NULL, "Error fork.");
	if (!pipex->parent)
		child_process(pipex, av[2]);

}
