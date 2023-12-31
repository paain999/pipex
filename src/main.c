/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:54:42 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/18 10:58:42 by dajimene         ###   ########.fr       */
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

	if (ac != 5)
		ft_error_exit(NULL, "Error, wrong number of arguments", 0, 0);
	else
	{
		new_pipex(&pipex);
		ft_pipex(&pipex, av, env);
	}
	free_all(&pipex);
	return (0);
}
