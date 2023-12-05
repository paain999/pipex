/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:15:50 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/05 10:37:47 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error_exit(char *path_from_envp, char **paths,
		char *message)
{
	int	i;

	if (path_from_envp)
		free(path_from_envp);
	if (paths)
	{
		i = 0;
		while (paths[i])
			free(paths[i++]);
		free(paths);
	}
	ft_putstr_fd(message, STDERR);
	exit(-1);
}

int	ft_open_and_check(char *file, int mode)
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