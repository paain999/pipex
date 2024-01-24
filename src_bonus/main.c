/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:54:42 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/18 13:36:35 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

void	put_here_doc(char **av, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

static void	here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		put_here_doc(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN);
		wait(NULL);
	}
}

void	pipex(char *cmd, char **env, int in_fd, int out_fd)
{
	pid_t	parent;
	int		end[2];

	if (pipe(end) == -1)
		exit(0);
	parent = fork();
	if (parent == -1)
		exit(0);
	if (!parent)
	{
		close(end[0]);
		dup2(in_fd, STDIN);
		dup2(end[1], STDOUT);
		exec(cmd, env);
	}
	else
	{
		waitpid(parent, NULL, 0);
		close(end[1]);
		dup2(out_fd, STDOUT);
		dup2(end[0], STDIN);
		exec(cmd, env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	out_fd;
	int	in_fd;
	int	i;

	if (ac < 5 || (ft_strcmp(av[1], "here_doc") == 0 && ac < 6))
		ft_error_exit(NULL, "Error, wrong number of arguments", 0, 0);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		out_fd = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		in_fd = open_file(av[1], STDIN);
		out_fd = open_file(av[ac - 1], STDOUT);
		dup2(in_fd, STDIN);
	}
	return (0);
}
