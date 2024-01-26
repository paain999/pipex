/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:54:42 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/26 15:08:01 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	new_pipex(t_pipex *pipex)
{
	pipex->cmd_args = NULL;
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->parent = 0;
	pipex->paths = NULL;
	pipex->correct_path = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (!env || !*env)
		return (0);
	if (ac != 5)
		ft_error_exit(NULL, "Error, wrong number of arguments", 0, 0);
	else
	{
		new_pipex(&pipex);
		get_path(env, &pipex);
		ft_pipex(&pipex, av, env);
	}
	free_all(&pipex);
	return (0);
}
