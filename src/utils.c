/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:28:51 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/12 20:01:04 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_path(char **env, t_pipex *pipex)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			pipex->paths = ft_split(ft_strdup(ft_strtrim(*env, "PATH=")), ':');
			while (*pipex->paths)
			{
				*pipex->paths = ft_strjoin(*pipex->paths, "/");
				printf("path: %s\n", *pipex->paths);
				pipex->paths++;
			}
		}
		env++;
	}
}
