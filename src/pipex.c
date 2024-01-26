/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:28:27 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/26 15:07:49 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	char	*check_path(t_pipex *pipex, char *cmd)
{
	char	*bin;
	int		i;

	i = 0;
	while (pipex->paths[i])
	{
		bin = ft_strdup(pipex->paths[i]);
		bin = ft_strjoin(bin, cmd);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		i++;
	}
	return (0);
}

static	void	execute(t_pipex *pipex, char *cmd, char **env)
{
	if (pipex->cmd_args)
		free(pipex->cmd_args);
	pipex->cmd_args = ft_split(cmd, ' ');
	if (ft_strchr(pipex->cmd_args[0], '/'))
		pipex->correct_path = pipex->cmd_args[0];
	else
		pipex->correct_path = check_path(pipex, pipex->cmd_args[0]);
	if (!pipex->correct_path)
		ft_error_exit(pipex,
			"Error, no valid path for this command.\n", pipex->in_fd,
			pipex->out_fd);
	execve(pipex->correct_path, pipex->cmd_args, env);
	ft_putstr_fd("pipex: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(": command not found\n", STDERR);
}

static	void	child_process(t_pipex *pipex, char *cmd, char **env)
{
	close(pipex->end[0]);
	dup2(pipex->in_fd, STDIN);
	dup2(pipex->end[1], STDOUT);
	execute(pipex, cmd, env);
}

static	int	ft_open_and_check(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == STDOUT)
	{
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ft_error_exit(NULL, "Error opening or creating the file.\n", 0, 0);
	}
	else if (mode == STDIN)
	{
		if (access(file, F_OK) == -1)
			ft_error_exit(NULL, "Error, No such file or directory\n", 0, 0);
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error_exit(NULL, "Error open", 0, 0);
	}
	return (fd);
}

void	ft_pipex(t_pipex *pipex, char **av, char **env)
{
	pipex->in_fd = ft_open_and_check(av[1], STDIN);
	pipex->out_fd = ft_open_and_check(av[4], STDOUT);
	if (pipe(pipex->end) == -1)
		ft_error_exit(NULL, "Error pipe.", 0, 0);
	pipex->parent = fork();
	if (pipex->parent == -1)
		ft_error_exit(NULL, "Error fork.", 0, 0);
	if (!pipex->parent)
		child_process(pipex, av[2], env);
	if (pipex->parent)
	{
		waitpid(pipex->parent, NULL, 0);
		close(pipex->end[1]);
		dup2(pipex->out_fd, STDOUT);
		dup2(pipex->end[0], STDIN);
		execute(pipex, av[3], env);
	}
}
