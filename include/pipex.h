/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:51 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/05 10:26:52 by dajimene         ###   ########.fr       */
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
	char	*path_from_envp;
	char	**paths;
	char	**cmd_args;
	pid_t	child_one;
	pid_t	child_two;
}		t_pipex;

void	ft_pipex(t_pipex *pipex, char **av, char **env);
void	ft_error_exit(char *path_from_envp, char **cmd_args, char *message);
int		ft_open_and_check(char *file, int mode);

#endif