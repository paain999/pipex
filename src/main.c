/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:54:42 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/13 12:27:07 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	new_pipex(t_pipex *pipex)
{
	pipex->cmd_args = NULL;
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->parent = NULL;
	pipex->paths = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac != 5)
		ft_error_exit(NULL, NULL, "Error, wrong number of arguments");
	else
	{
		new_pipex(&pipex);
		ft_pipex(&pipex, av, env);
	}
	return (0);
}
