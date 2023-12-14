/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:54:42 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/13 13:48:03 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"
#include <sys/wait.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		end[2];
	char	**paths;
	char	**cmd_args;
	pid_t	parent;
}		t_pipex;

static void	new_pipex(t_pipex *pipex)
{
	pipex->cmd_args = 0;
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->parent = 0;
	pipex->paths = 0;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	char	**paths = pipex->paths;

	new_pipex(pipex);
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			paths = ft_split(ft_strdup(ft_strtrim(*env, "PATH=")), ':');
			while (*paths)
			{
				*paths = ft_strjoin(*pipex->paths, "/");
				printf("path: %s\n", *pipex->paths);
				paths++;
			}
			break ;
		}
		env++;
	}
	return (0);
}
