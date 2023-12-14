/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:51 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:21 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h" 
# include <sys/wait.h>

# define STDERR 2
# define STDIN 0
# define STDOUT 1

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		end[2];
	char	**paths;
	char	**cmd_args;
	pid_t	parent;
}		t_pipex;

void	ft_pipex(t_pipex *pipex, char **av, char **env);
void	ft_error_exit(char *path_from_envp, char **cmd_args, char *message);

#endif