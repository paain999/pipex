/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:28:51 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/26 14:53:54 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_all(t_pipex *pipex)
{
	int	i;

	if (pipex->correct_path)
		free(pipex->correct_path);
	if (pipex->cmd_args)
	{
		i = 0;
		while (pipex->cmd_args[i])
			free(pipex->cmd_args[i++]);
		free(pipex->cmd_args);
	}
	if (pipex->paths)
	{
		i = 0;
		while (pipex->paths[i])
			free(pipex->paths[i++]);
		free(pipex->paths);
	}
	free(pipex);
}

void	ft_error_exit(t_pipex *pipex, char *message, int fd1, int fd2)
{
	if (fd1)
		close(fd1);
	if (fd2)
		close(fd2);
	if (pipex)
		free_all(pipex);
	ft_putstr_fd(message, STDERR);
	exit(1);
}

void	get_path(char **env, t_pipex *pipex)
{
	int		i;
	char	**envp;

	envp = env;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
		{
			*envp += 5;
			i = 0;
			pipex->paths = ft_split(*envp, ':');
			while (pipex->paths[i])
			{
				pipex->paths[i] = ft_strjoin(pipex->paths[i], "/");
				i++;
			}
			break ;
		}
		envp++;
	}
	if (!*envp)
		ft_error_exit(NULL, "Error, no PATH variable found.\n", 0, 0);
}
