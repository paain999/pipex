/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:15:50 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/04 21:52:05 by dajimene         ###   ########.fr       */
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
